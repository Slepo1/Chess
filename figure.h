#pragma once

#include <QLabel>
#include <QObject>

class Cell; // Мэйби из-за этого отрисовывает плохо

class Figure : public QLabel
{
    Q_OBJECT

public:
    enum Color {WHITE, BLACK};

    Figure (Color color, const QVector<QVector<Cell*>>& backfield, QWidget *parent = nullptr);
    virtual ~Figure();

    // Принимает массив указателей на Cell
    void calculateMove ();

    Color getColor () const { return m_color; }

private:
    Color m_color;

    // Логика перемещения для белой ладьи
    virtual void performActionForWhite ();

    // Логика перемещения для чёрной ладьи
    virtual void performActionForBlack ();

protected:
    const QVector<QVector<Cell*>>& m_backfield;
};



