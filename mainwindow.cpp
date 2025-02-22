#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->centralwidget->resize(640, 480);
    //ui->frame->setMinimumSize(200, 200);
}



MainWindow::~MainWindow()
{
    delete ui;
}
