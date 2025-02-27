#include "mainwindow.h"


#include <QApplication>
#include <QDebug>
#include <QLoggingCategory>


int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);

    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true); // для вывода в консоль qDebug()

    qDebug() << "hello lefty)";


    MainWindow w;
    w.show();


    return a.exec();
}
