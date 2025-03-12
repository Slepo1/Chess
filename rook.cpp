#include "rook.h"

Rook::Rook (QWidget *parent) : Figure (parent)
{

    // Изображение белой ладьи
    QPixmap pixmap(":/wFigures/resources/tatiana/wR.png");

    if (pixmap.isNull ())
    {
        throw std::runtime_error("Изображение для ладьи не найдено");
    }

    setPixmap (pixmap);
}

Rook::~Rook ()
{

}

void Rook::moveTo (MainWindow *window)
{

}
