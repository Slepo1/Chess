#pragma once

#include <iostream>
#include <QFile>
#include <QMainWindow>
#include "cell.h"
#include "figure.h"

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

    void mousePressEvent (QMouseEvent *event) override;

    // Логика при нажатии мыши на Figure
    void pressFig ();

};

