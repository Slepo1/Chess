#pragma once

#include <iostream>
#include <QFile>
#include <QMainWindow>
#include "cell.h"
#include "figure.h"
#include "rook.h"
#include "gamestats.h"

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

private slots:
    void on_butNextStep_clicked();

    void updateCountStep ();

private:
    Ui::MainWindow *ui;

    // Объект игровой статистики
    GameStats &stats;

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

    /** Этот прикол делается только потому, что если в конструкторе Cell сохранять
     * baseStyleSheet, то styleSheet из qt designer он не сохраняет почему-то, а
     * из конструктора mainwindow уже сохраняет с параметрами установленными в
     * qt designer
     */
    void saveCellColor ();

    // Закрашивание обратно в обычный цвет Cell'a
    void setCellBaseColor ();

    // Чтобы все виджеты в gridLayout имели одинаковые размеры
    void stretchCoef ();
};

