#include "cell.h"

Cell::Cell(QWidget *&newWidget)
{
    setMinimumSize(200, 200);
    qDebug() << "Privet";
}

void Cell::newResize()
{
    resize(200, 200);
}
