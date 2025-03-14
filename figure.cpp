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

    this->parent = parent;

    // Ставим фигуру на клетку, которую передали при создании в конструкторе
    parent->addFig(this);

    // Привязываю имя для фигуры относительно стартовой клетки
    setObjectName ("Figure_" + parent->objectName ());

    // Нужно задать начальное значения индексов
    getIndexCell ();
}

Figure::~Figure ()
{

}

void Figure::calculateMove ()
{
    // Надо обновить индексы местонахождения фигуры перед ходом
    getIndexCell ();
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
            if (parent == m_backfield[i][j])
            {
                index.column = i;
                index.row = j;
            }
        }
    }
}
