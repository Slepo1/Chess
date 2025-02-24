#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->background->setStyleSheet( "background: url(:/img/resources/backgroundImg.jpg)" );

    //ui->background->setStyleSheet("background-color: #FF5722;");

    //ui->background->setStyleSheet("background-color: #FF5722;");

    //qDebug() << ui->frame->styleSheet();


}



MainWindow::~MainWindow()
{
    delete ui;
}
