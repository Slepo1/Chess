#pragma once

#include <iostream>
#include <QFile>
#include <QMainWindow>
#include "cell.h"
#include "figure.h"
#include "rook.h"

// Кол-во фигур одного цвета
static constexpr int FIGURE_COUNT = 16;

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

    bool clickProcess () { return clickProcessing; }

    void setClickProcess (bool clicking) { clickProcessing = clicking; }

private:
    Ui::MainWindow *ui;

    // Флаг означающий нажал ли пользователь на фигуру или нет
    bool clickProcessing;

    // Создание двумерного массива указателей на Cell'ы моего поля
    QVector<QVector<Cell*>> backfield;

    // Массив указателей на белые фигуры
    QVector <Figure*> whiteFigure;

    // Массив указателей на черные фигуры
    QVector <Figure*> blackFigure;

    void resizeFigure ();

    void setupStyle ();

    // Загрузка всех фигур на backfield
    void setupFigure ();



    void loadCells ();

    void showCells ();

    void mousePressEvent (QMouseEvent *event) override;

    // Логика при нажатии мыши на Figure
    void clickOnFig (Figure *figure);

    // Теперь добавляет QLabel на весь Cell, а также центрирует его
    //void addFig (Figure *figure);

    // Чтобы все виджеты в gridLayout имели одинаковые размеры
    void stretchCoef ();
};

