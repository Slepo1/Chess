#pragma once

#include "colors.h"
#include <QDialog>

namespace Ui
{
class NotificationWin;
}

class NotificationWin : public QDialog
{
    Q_OBJECT

public:
    explicit NotificationWin (Color color, QWidget *parent = nullptr);
    ~NotificationWin ();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NotificationWin *ui;
};


