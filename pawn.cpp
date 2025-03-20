#include "pawn.h"

Pawn::Pawn (Color color, const QVector<QVector<Cell *>> &backfield,
            Cell *parent) : Figure (color, backfield, parent)
{
    QPixmap pixmap;
    switch (getColor ())
    {
    case WHITE:
        pixmap.load (":/wFigures/resources/tatiana/wP.png");
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белой пешки не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        // Изображение чёрной ладьи
        pixmap.load (":/bFigures/resources/tatiana/bP.png");
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для чёрной пешки не найдено");
        }
        setPixmap (pixmap);
        break;
    default:
        break;
    }

}

Pawn::~Pawn ()
{
}

void Pawn::performActionForWhite ()
{

}

void Pawn::performActionForBlack ()
{

}
