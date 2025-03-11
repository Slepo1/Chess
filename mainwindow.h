#pragma once

#include <iostream>
#include <QFile>
#include <QMainWindow>
#include "cell.h"
#include "figure.h"
#include "rook.h"

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

    // Создание двумерного массива указателей на Cell'ы моего поля
    Cell *backfield[8][8];

    //Rook rook;

    void setupStyle ();

    void loadCells ();

    void showCells ();

    void mousePressEvent (QMouseEvent *event) override;

    // Логика при нажатии мыши на Figure
    void clickOnFig ();

    // Теперь добавляет QLabel на весь Cell, а также центрирует его
    void addFig ();

    // Чтобы все виджеты в gridLayout имели одинаковые размеры
    void stretchCoef ();
};

