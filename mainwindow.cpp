#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setupStyle();


    /*QLabel *fig = new QLabel (ui->frame_8);
    fig->setObjectName ("fig");

    ui->frame_8->getLayout().addWidget(fig);

    fig->setText("PRIKOL"); */
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

void MainWindow::mousePressEvent (QMouseEvent *event)
{
    QPoint mousePos = event->position ().toPoint ();
    qDebug () << mousePos;
    //qDebug () << childAt (mousePos)->objectName ();
    QObject *child = childAt (mousePos);
    // Логика если нажимаемый объект оказался Figure или его наследником
    if (auto *specificChild = qobject_cast<Figure *> (child))
    {
        qDebug () << specificChild->objectName ();


    }

}

void pressFig ()
{

}
