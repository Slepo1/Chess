#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setupStyle();

    // Заполнение двумерного массива Cell'ами
    loadCells ();

    showCells ();

    addFig ();



    /*QLabel *fig = new QLabel (ui->frame_8);
    fig->setObjectName ("fig");

    ui->frame_8->getLayout().addWidget(fig);

    fig->setText("PRIKOL"); */





    stretchCoef ();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            QString currentObjectName = QString ("cell_%1").arg (numberCell);
            backfield[i][j] = this->findChild<Cell*>(currentObjectName);
            numberCell++;

            // Ошибка, если метод findChild не смог найти нужный объект Cell currentObjectName
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
    qDebug () << mousePos;
    //qDebug () << childAt (mousePos)->objectName ();
    QObject *child = childAt (mousePos);
    // Логика если нажимаемый объект оказался Figure или его наследником
    //if (auto *specificChild = qobject_cast<Figure *> (child))
    if (auto *specificChild = qobject_cast<QLabel *> (child))
    {
        qDebug () << specificChild->objectName ();


    }

}

void clickOnFig ()
{

}

void MainWindow::addFig ()
{

    Rook *tmp = new Rook ();
    tmp->setText ("ROOK");
    tmp->setAlignment(Qt::AlignCenter);
    // Лейбл расширяется по всей доступной площади
    tmp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->cell_1->getLayout ().addWidget(tmp);
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
