#pragma once

#include <iostream>
#include <QFile>
#include <QMainWindow>
#include "cell.h"
#include "figure.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"
#include "gamestats.h"
#include "transformpawndialog.h"
#include "notificationwin.h"
#include <thread>
#include "colors.h"

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

    void transformPawn (Color color);

private:
    Ui::MainWindow *ui;

    int result;

    // Объект игровой статистики
    GameStats &stats;

    // Поток который вызывается для обновления
    std::thread m_threadUpdatePositions;

    Figure *chosenFigure;

    // Флаг означающий нажал ли пользователь на фигуру или нет
    bool clickProcessing;

    // Создание двумерного массива указателей на Cell'ы моего поля
    QVector<QVector<Cell*>> backfield;

    // Массив указателей на белые фигуры
    QVector <Figure*> whiteFigure;

    // Массив указателей на черные фигуры
    QVector <Figure*> blackFigure;

    // Массив указателей для выбывших фигур
    QVector <Figure*> killedFigures;

    // Массив указателей для замененных пешек
    QVector <Figure*> transformPawns;

    void resizeFigure ();

    void setupStyle ();

    // Загрузка всех фигур на backfield
    void setupFigure ();

    void loadCells ();

    void showCells ();

    void showLocationFigures ();

    void updateVectorFigures (Figure *figure);

    void mousePressEvent (QMouseEvent *event) override;

    void checkWin (Figure *figure);

    // Логика при нажатии мыши на Figure
    void clickOnFig (Figure *figure);

    /* Этот прикол делается только потому, что если в конструкторе Cell сохранять
     * baseStyleSheet, то styleSheet из qt designer он не сохраняет почему-то, а
     * из конструктора mainwindow уже сохраняет с параметрами установленными в
     * qt designer
     */
    void saveCellColor ();

    // Закрашивание обратно в обычный цвет Cell'a
    void setBasePossibleCell ();

    // Чтобы все виджеты в gridLayout имели одинаковые размеры
    void stretchCoef ();

    // Обновление index'ов всех существующих фигур, в идеале переписать на новый поток!
    void updateIndexFigures ();

    // Запускаем новый поток призапуске функции обновления индекса
    void startUpdatePositionsThread ();

    // Ждём завершения потока, созданного для обновления индексов фигур
    /// Очень важно при завершении хода, нужно сделать вызов этой функции!!!
    void waitUpdatePositionThread ();

    void clearKilledFigures ();

    void clearTransformFigures ();
};

