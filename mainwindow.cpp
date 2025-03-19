#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow (QWidget *parent)
    : QMainWindow (parent), ui (new Ui::MainWindow),
      stats (GameStats::getInstance ())
{
    ui->setupUi(this);

    setupStyle();

    // Задаю кол-во фигур одного цвета
    resizeFigure ();

    // Заполнение двумерного массива Cell'ами
    loadCells ();

    showCells ();

    setupFigure ();

    // Подключение слотов изменения счётчика хода
    if(!connect (&stats, SIGNAL(changeCountStep()), this, SLOT(updateCountStep ())))
        throw;

    // Устанавливаем начальный номер хода и стартовый цвет
    stats.setNumberCurrentTurn (1);
    stats.setCurrentColorTurn (WHITE);

    saveCellColor ();

    updateCountStep ();

    stretchCoef ();

    // Надо создать отдельный поток, который каждый ход для каждой фигуры будет считывать getIndexCell, Искать будем по массиву фигур
    // Потому что сейчас он обновляет каждый раз при calculateMove, при нажатии на фигуру!
}

MainWindow::~MainWindow()
{
    waitUpdatePositionThread ();

    delete ui;
}

void MainWindow::resizeFigure ()
{
    whiteFigure.resize (FIGURE_COUNT);
    blackFigure.resize (FIGURE_COUNT);
}

void MainWindow::setupStyle()
{
    QFile styleFile("chess.qss");  // Используем относительный путь

    if (!styleFile.exists()) {
        throw std::runtime_error("Файл chess.qss не найден");
    }

    if (!styleFile.open(QFile::ReadOnly)) {
        throw std::runtime_error("Не удалось открыть файл chess.qss");
    }

    QString style(styleFile.readAll());
    qApp->setStyleSheet(style);

    styleFile.close();
}


void MainWindow::loadCells ()
{
    int numberCell = 1;
    backfield.resize (8);
    for (int i = 0; i < 8; i++)
    {
        backfield[i].resize(8);
        for (int j = 0; j < 8; j++)
        {
            QString currentObjectName = QString ("cell_%1").arg (numberCell);
            backfield[i][j] = this->findChild<Cell*>(currentObjectName);
            numberCell++;

            // Ошибка, если метод findChild не смог найти нужный объект Cell
            if (!backfield[i][j])
                throw std::runtime_error (QString ("Объект '%1' не найден")
                                              .arg (currentObjectName)
                                              .toStdString ());
        }

    }

}

void MainWindow::showCells ()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            qDebug() << backfield[i][j]->objectName ();
        }
        qDebug () << "\n";

    }
}

void MainWindow::mousePressEvent (QMouseEvent *event)
{
    QPoint mousePos = event->position ().toPoint ();
    QObject *child = childAt (mousePos);

    if (clickProcess () == true)
    {
        // Логика если был клик на Cell, на который можно ходить
        if (auto *specificChildCell = qobject_cast<Cell *> (child))
        {
            if (specificChildCell->possibleCell ())
            {
                // Логика перестановки выбранной фигуры
                qDebug() << "";
                qDebug() << "getLocationCell: " + chosenFigure->getLocationCell ()->objectName();
                specificChildCell->addFig (chosenFigure);
                qDebug() << "getLocationCell: " + chosenFigure->getLocationCell ()->objectName();

                // Ознаменование следующего хода
                stats.nextNumberCurrentTurn ();
            }
            // Если клетка не доступна к ходу, то просто ничего не делаем
        }
        // Логика если был клик на фигуру вражеского цвета
        else if (auto *specificChildEnemy = qobject_cast<Figure *> (child))
        {
            if (specificChildEnemy->getLocationCell ()->possibleCell () != stats.currentColorTurn ())
            {
                // Логика убийства вражеской фигуры и перестановки выбранной
                //




                // Ознаменование следующего хода
                stats.nextNumberCurrentTurn ();
            }
        }





        // Закрашиваем обратно все клетки в базовый цвет
        setCellBaseColor ();
        // Процесс клика выключаем
        setClickProcess (false);
    }
    else
    {
        qDebug () << mousePos;

        // Логика если нажимаемый объект оказался Figure или его наследником
        /// Надо устраивать проверку на цвет фигуры и глобальный цвет хода
        if (auto *specificChild = qobject_cast<Figure *> (child))
        {
            // Здесь надо оставить для синхронизации, чтобы перед расчётом хода были обновлённые данные
            waitUpdatePositionThread ();


            // Сохраняем выбранную фигуру
            chosenFigure = qobject_cast<Figure *> (child);
            // Пользователь нажал на фигуру
            clickOnFig (specificChild);

            // Процесс клика включаем только если пользователь нажал на фигуру
            if (clickProcess () == true)
            {
                setClickProcess (false);
            }
            else
            {
                setClickProcess (true);
            }
        }


    }



}

void MainWindow::clickOnFig (Figure *figure)
{
    // Нужно будет сделать дополнительную проверку на то, является ход белых/чёрных и цвет фигуры
    qDebug () << figure->objectName ();

    // Начинаем процесс вычисления нужных нам Cell'ов
    figure->calculateMove ();

}


void MainWindow::saveCellColor ()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            backfield[i][j]->saveStyleSheet ();
        }
    }
}

void MainWindow::setCellBaseColor ()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            backfield[i][j]->setBaseStyleSheet ();
        }
    }
}

void MainWindow::stretchCoef ()
{
    // Устанавливаем одинаковые коэффициенты растяжения для всех строк и столбцов
    for (int i = 0; i < 10; ++i)
    {
        ui->gridLayout->setRowStretch(i, 1);
        ui->gridLayout->setColumnStretch(i, 1);
    }

}

void MainWindow::updateIndexFigures ()
{
    // Смысл функции запускаться в отдельном потоке

    for (int i = 0; i < whiteFigure.size(); i++)
    {
        whiteFigure[i]->getIndexCell ();
    }

    for (int i = 0; i < blackFigure.size(); i++)
    {
        blackFigure[i]->getIndexCell ();
    }
}

void MainWindow::on_butNextStep_clicked()
{
    stats.nextNumberCurrentTurn ();

    /*qDebug() << "";
    qDebug() << "getLocationCell: " + whiteFigure[0]->getLocationCell ()->objectName();
    backfield[4][4]->addFig (whiteFigure[0]);
    qDebug() << "getLocationCell: " + whiteFigure[0]->getLocationCell ()->objectName();*/
}

void MainWindow::updateCountStep ()
{
    // При изменении хода обновляем значение в UI
    ui->lblCurrentStep->setText (QString::number (stats.numberCurrentTurn ()));

    // Обновляем цвет в зависимости номера хода
    if (stats.numberCurrentTurn () % 2 == 1)
        stats.setCurrentColorTurn (WHITE);
    else
        stats.setCurrentColorTurn (BLACK);


    if (stats.currentColorTurn () == WHITE)
    {
        ui->lblCurrentColor->setText("Белых");
    }
    else if (stats.currentColorTurn () == BLACK)
    {
        ui->lblCurrentColor->setText("Чёрных");
    }

    startUpdatePositionsThread ();
}

void MainWindow::startUpdatePositionsThread ()
{
    // Если каким-то чудом ход завершился не после перестановки фигуры
    waitUpdatePositionThread ();

    // Чтобы поток обновления фигур не ломался, иначе он вызывается на первом ходу более одного раза до уничтожения
    if (stats.numberCurrentTurn () == 1)
        return;

    m_threadUpdatePositions = std::thread(&MainWindow::updateIndexFigures, this);
}

void MainWindow::waitUpdatePositionThread ()
{
    // Только в случае если пользователь нажал на фигуру нам необходимо убедиться что поток завершил обновления индексов позиций
    if (m_threadUpdatePositions.joinable ())
                m_threadUpdatePositions.join ();
}
