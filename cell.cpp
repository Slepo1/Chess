#include "cell.h"

Cell::Cell (QFrame *&newWidget)
{
    //setMinimumSize(200, 200);
    //qDebug() << "Privet";
    setStyleSheet ("border: 1px solid black;");
}

void Cell::newResize ()
{
    resize (200, 200);
}
