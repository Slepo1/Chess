#pragma once

#include <iostream>
#include <QFile>
#include <QMainWindow>
#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget *parent = nullptr);
    ~MainWindow ();

private:
    Ui::MainWindow *ui;

    void setupStyle ();

    //Cell cellField();

};

