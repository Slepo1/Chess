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

    // Слот по вызову диалога превращения пешки в фигуру
    if (!connect (&stats, SIGNAL (startTransformPawn (Color)), this, SLOT (transformPawn (Color))))
        throw;

    saveCellColor ();

    updateCountStep ();

    stretchCoef ();
}

MainWindow::~MainWindow()
{
    waitUpdatePositionThread ();

    // Может быть нужно после delete ui поместить
    clearKilledFigures ();

    clearTransformFigures ();

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

void MainWindow::showLocationFigures ()
{
    for (int i = 0; i < whiteFigure.size (); i++)
    {
        qDebug () << whiteFigure[i]->objectName () + " column: " +
                         QString::number (whiteFigure[i]->index.column) +
                         " row: " + QString::number (whiteFigure[i]->index.row);
    }

    for (int i = 0; i < blackFigure.size (); i++)
    {
        qDebug () << blackFigure[i]->objectName () + " column: " +
                         QString::number (blackFigure[i]->index.column) +
                         " row: " + QString::number (blackFigure[i]->index.row);
    }
}

void MainWindow::updateVectorFigures (Figure *figure)
{
    for (int i = 0; i < whiteFigure.size (); i++)
    {
        if (whiteFigure[i] == figure)
            whiteFigure.remove (i);
    }

    for (int i = 0; i < blackFigure.size(); i++)
    {
        if (blackFigure[i] == figure)
            blackFigure.remove (i);
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
                qDebug() << "Фигура переставлена на пустую клетку";
                specificChildCell->addFig (chosenFigure);

                // Ознаменование следующего хода
                stats.nextNumberCurrentTurn ();
            }
            // Если клетка не доступна к ходу, то просто ничего не делаем
        }
        // Логика если был клик на фигуру вражеского цвета
        else if (auto *specificChildEnemy = qobject_cast<Figure *> (child))
        {
            // Надо проверять находится на possibleCell?
            if (specificChildEnemy->getColor () != stats.currentColorTurn ())
            {
                if (!specificChildEnemy->getLocationCell ()->possibleCell ())
                {
                    setClickProcess (false);
                    // Закрашиваем обратно все клетки в базовый цвет
                    setBasePossibleCell ();
                    return;
                }

                Cell *chosenCell = specificChildEnemy->getLocationCell ();

                // Логика убийства вражеской фигуры и перестановки выбранной
                Figure *killedFigure = qobject_cast<Figure *> (specificChildEnemy);


                // Обновляем вектор оставшихся фигур, и перемещаем новую фигуру на место старой
                killedFigures.push_back (killedFigure);
                updateVectorFigures (killedFigure);
                chosenCell->removeFig (killedFigure);
                chosenCell->addFig (chosenFigure);

                checkWin (killedFigure);


                // Ознаменование следующего хода
                stats.nextNumberCurrentTurn ();
                showLocationFigures ();
            }
        }





        // Закрашиваем обратно все клетки в базовый цвет
        setBasePossibleCell ();
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
            // Если первый клик пользователя был на вражескую фигуру, то реагировать на это не нужно
            if (specificChild->getColor () != stats.currentColorTurn ())
                return;


            // Здесь надо оставить для синхронизации, чтобы перед расчётом хода были обновлённые данные
            waitUpdatePositionThread ();


            // Сохраняем выбранную фигуру
            chosenFigure = qobject_cast<Figure *> (child);
            // Пользователь нажал на фигуру
            clickOnFig (specificChild);


            // Включаем процес клика, тк пользователь нажал на свою фигуру
            setClickProcess (true);
        }


    }
}

void MainWindow::checkWin (Figure *figure)
{
    King *king = dynamic_cast<King*>(figure);
    if (king != nullptr)
    {
        NotificationWin d (stats.currentColorTurn (), this);
        if (d.exec () == QDialog::Accepted)
        {
            close ();
        }
        std::cout << "Уничтоженный объект является королём." << std::endl;
    }
    else
    {
        std::cout << "Уничтоженный объект не является королём." << std::endl;
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

void MainWindow::setBasePossibleCell ()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Вот здесь checkFig (вызывается на местах где есть клетки)
            backfield[i][j]->setPossibleCell (false);
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
    // Запускается в отдельном потоке
    for (int i = 0; i < whiteFigure.size(); i++)
    {
        whiteFigure[i]->getIndexCell ();
    }

    for (int i = 0; i < blackFigure.size(); i++)
    {
        blackFigure[i]->getIndexCell ();
    }
    // Видимо обновление индексов у черных фигур не происходит
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

void MainWindow::transformPawn (Color color)
{
    // Есть цвет и accept(), есть еще и index из gamestats, и также есть enum который будет возращаться accept ()
    TransformPawnDialog d (color, this);
    if (d.exec () == QDialog::Accepted)
    {
        Cell *chosenCell = backfield[stats.index.row][stats.index.column];

        // Поиск внутри Cell'a объекта типа QLabel или его наследников
        QList<Figure*> figures = chosenCell->findChildren<Figure*>();
        if (figures.isEmpty())
        {
            // Не нашли пешку на указаном индексе
            return;
        }
        Figure *figure = figures[0];

        // В figure -> указатель на пешку

        result = d.getResult();


        if (result == ROOK)
        {
        // Обновляем вектор оставшихся фигур, и меняем пешку на новую фигуру
            transformPawns.push_back (figure);
            updateVectorFigures (figure);
            chosenCell->removeFig (figure);
            Figure *newFigure = new Rook (color, backfield, chosenCell);
            whiteFigure.push_back (newFigure);
        }
        else if (result == KNIGHT)
        {
            // Обновляем вектор оставшихся фигур, и меняем пешку на новую фигуру
            transformPawns.push_back (figure);
            updateVectorFigures (figure);
            chosenCell->removeFig (figure);
            Figure *newFigure = new Knight (color, backfield, chosenCell);
            whiteFigure.push_back (newFigure);
        }
        else if (result == BISHOP)
        {
            // Обновляем вектор оставшихся фигур, и меняем пешку на новую фигуру
            transformPawns.push_back (figure);
            updateVectorFigures (figure);
            chosenCell->removeFig (figure);
            Figure *newFigure = new Bishop (color, backfield, chosenCell);
            whiteFigure.push_back (newFigure);
        }
        else if (result == QUEEN)
        {
        // Обновляем вектор оставшихся фигур, и меняем пешку на новую фигуру
            transformPawns.push_back (figure);
            updateVectorFigures (figure);
            chosenCell->removeFig (figure);
            Figure *newFigure = new Queen (color, backfield, chosenCell);
            whiteFigure.push_back (newFigure);
        }

    }
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

void MainWindow::clearKilledFigures ()
{
    for (int i = 0; i < killedFigures.size(); i++)
    {
        delete killedFigures[i];
    }
}

void MainWindow::clearTransformFigures ()
{
    for (int i = 0; i < transformPawns.size (); i++)
        delete transformPawns[i];
}
