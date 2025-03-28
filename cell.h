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

    void setBaseStyleSheet ();

public:
    Cell (QFrame *parent);
    virtual ~Cell ();

    void fixedResize ();

    // Метод лучше оставить отдельный, тк будем проверять checkfig заполненность клетки
    void addFig (Figure *figure);

    void removeFig (Figure *figure);

    void setPossibleCell (bool possible);

    bool possibleCell () { return m_possible; }

    // Достать цвет фигуры внутри клетки
    Color colorFigure ();

    void saveStyleSheet ();
};


