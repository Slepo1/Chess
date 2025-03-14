#include "figure.h"
#include "cell.h"

Figure::Figure (Color color, const QVector<QVector<Cell *>> &backfield,
                Cell *parent)
    : m_color (color), m_backfield (backfield)
{
    // Центрируем фигуру
    setAlignment(Qt::AlignCenter);
    // Лейбл расширяется по всей доступной площади
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Ставим фигуру на клетку, которую передали при создании в конструкторе
    parent->addFig(this);

    //setObjectName ("Figure" + parent->objectName ());
}

Figure::~Figure ()
{

}

void Figure::calculateMove ()
{
    // Логика перемещения
    switch (getColor ())
    {
    case WHITE:
        performActionForWhite ();
        break;
    case BLACK:
        performActionForBlack ();
        break;
    default:
        break;
    }
}

void Figure::performActionForWhite ()
{

}

void Figure::performActionForBlack ()
{

}
