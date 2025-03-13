#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupStyle();

    // Задаю кол-во фигур одного цвета
    resizeFigure ();

    // Заполнение двумерного массива Cell'ами
    loadCells ();

    showCells ();

    setupFigure ();

    //addFig ();



    stretchCoef ();
}

MainWindow::~MainWindow()
{
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

    if (clickProcess () == true)
    {
        // Логика если пользователь уже нажал на figure



        // Процесс клика выключаем
        setClickProcess (false);
    }
    else
    {
        qDebug () << mousePos;
        QObject *child = childAt (mousePos);

        // Логика если нажимаемый объект оказался Figure или его наследником
        if (auto *specificChild = qobject_cast<Figure *> (child))
        {
            // Пользователь нажал на фигуру
            clickOnFig (specificChild);

            // Процесс клика включаем только если пользователь нажал на фигуру
            setClickProcess (true);
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


void MainWindow::stretchCoef ()
{
    // Устанавливаем одинаковые коэффициенты растяжения для всех строк и столбцов
    for (int i = 0; i < 10; ++i)
    {
        ui->gridLayout->setRowStretch(i, 1);
        ui->gridLayout->setColumnStretch(i, 1);
    }

}
