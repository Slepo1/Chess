#include "figure.h"

Figure::Figure (Color color, const QVector<QVector<Cell *>> &backfield,
                QWidget *parent)
    : QLabel (parent), m_color (color), m_backfield (backfield)
{
    // Центрируем фигуру
    setAlignment(Qt::AlignCenter);
    // Лейбл расширяется по всей доступной площади
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


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
