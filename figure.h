#pragma once

#include <QLabel>
#include <QObject>

class Cell;

class Figure : public QLabel
{
    Q_OBJECT

public:
    enum Color {WHITE, BLACK};

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

    // Логика перемещения для белой ладьи
    virtual void performActionForWhite ();

    // Логика перемещения для чёрной ладьи
    virtual void performActionForBlack ();

    // Поиск индексов клетки в которой находится фигура
    void getIndexCell();

protected:
    const QVector<QVector<Cell*>>& m_backfield;

};



