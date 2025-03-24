#include "figure.h"
#include "cell.h"

Figure::Figure (Color color, const QVector<QVector<Cell *>> &backfield,
                Cell *parent)
    : m_color (color), m_backfield (backfield), stats (GameStats::getInstance ())
{
    // Центрируем фигуру
    setAlignment(Qt::AlignCenter);
    // Лейбл расширяется по всей доступной площади
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->parent = parent;

    // Ставим фигуру на клетку, которую передали при создании в конструкторе
    parent->addFig(this);


    // Нужно задать начальное значения индексов
    getIndexCell ();

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

void Figure::getIndexCell ()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (getLocationCell ()== m_backfield[i][j])
            {
                index.column = j;
                index.row = i;
            }
        }
    }
}

Cell *Figure::getLocationCell ()
{
    // Иначе значение parent не обновляется при смене родителя, даже после setParent... :(
    parent = dynamic_cast<Cell*>(this->parentWidget ());
    return parent;
}
