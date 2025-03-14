#include "rook.h"

Rook::Rook (Color color, const QVector<QVector<Cell *>> &backfield,
            Cell *parent)
    : Figure (color, backfield, parent)
{
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

}

void Rook::performActionForBlack ()
{

}

