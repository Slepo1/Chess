#include "rook.h"
#include "cell.h"

Rook::Rook (Color color, const QVector<QVector<Cell *>> &backfield,
            Cell *parent)
    : Figure (color, backfield, parent)
{

    // Figure ставит пустой лейбл и растягивает его на всю клетку, а здесь просто загрузка картинки
    QPixmap pixmap;
    switch (getColor ())
    {
    case WHITE:
        // Изображение белой ладьи
        pixmap.load (":/wFigures/resources/tatiana/wR.png");
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белой ладьи не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        // Изображение чёрной ладьи
        pixmap.load (":/bFigures/resources/tatiana/bR.png");
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для чёрной ладьи не найдено");
        }
        setPixmap (pixmap);
        break;
    default:
        break;
    }
}

Rook::~Rook ()
{

}

void Rook::performActionForWhite ()
{
    // Пройдемся по строкам
    for (int i = 0; i < 8; i++)
    {
        m_backfield[index.column][i]->setPossibleCell (true);
    }

    // Пройдемся по колоннам
    for (int i = 0; i < 8; i++)
    {
        m_backfield[i][index.row]->setPossibleCell (true);
    }
}

void Rook::performActionForBlack ()
{

}

