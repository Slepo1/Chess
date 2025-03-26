#include "notificationwin.h"
#include "ui_notificationwin.h"
#include "mainwindow.h"

NotificationWin::NotificationWin (Color color, QWidget *parent)
    : QDialog (parent), ui (new Ui::NotificationWin)
{
    ui->setupUi (this);

    if (color == WHITE)
        ui->lblColor->setText ("БЕЛЫЕ");
    else if (color == BLACK)
        ui->lblColor->setText ("ЧЁРНЫЕ");
}

NotificationWin::~NotificationWin () { delete ui; }

void NotificationWin::on_pushButton_clicked()
{
    accept ();
}

