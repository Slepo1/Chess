#pragma once

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>
#include "figure.h"
#include "gamestats.h"

class Cell : public QFrame
{
    Q_OBJECT

    // Объект игровой статистики
    GameStats &stats;

    void createLayout ();

    QHBoxLayout *horizontalLayout;

    bool checkFig ();

    //void mousePressEvent (QMouseEvent *event) override;

    QHBoxLayout &getLayout ();

    // Флаг означающий можно ли ставить туда фигуру
    bool m_possible;

    // Храним базовый styleSheet
    QString baseStyleSheet;

public:
    Cell (QFrame *parent);

    void newResize ();

    // Метод лучше оставить отдельный, тк будем проверять checkfig заполненность клетки
    void addFig (Figure *figure);

    void setPossibleCell (bool possible);

    bool possibleCell () { return m_possible; }

    // Достать указатель на фигуру внутри клетки
    Color colorFigure ();

    void saveStyleSheet ();

    void setBaseStyleSheet ();
};


