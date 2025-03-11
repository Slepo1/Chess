#include "figure.h"

Figure::Figure (QWidget *parent) : QLabel (parent)
{
    // Сделать падинги ноль, чтобы label занимал весь фрейм, и childAt вовзращал label


}

Figure::~Figure ()
{

}

void Figure::moveTo (const QPoint newPosition)
{
    // Логика перемещения
}
