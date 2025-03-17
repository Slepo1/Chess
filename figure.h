#pragma once

#include <QLabel>
#include <QObject>
#include "colors.h"

class Cell;

class Figure : public QLabel
{
    Q_OBJECT

public:

    struct
    {
        int column;
        int row;
    } index;

    Figure (Color color, const QVector<QVector<Cell *>> &backfield,
            Cell *parent);
    virtual ~Figure();

    // Принимает массив указателей на Cell
    void calculateMove ();

    Color getColor () const { return m_color; }

private:
    Color m_color;

    Cell *parent;

    // Логика перемещения для белой фигуры
    virtual void performActionForWhite ();

    // Логика перемещения для чёрной фигуры
    virtual void performActionForBlack ();

    // Поиск индексов клетки в которой находится фигура
    void getIndexCell();

protected:
    const QVector<QVector<Cell*>>& m_backfield;

};



