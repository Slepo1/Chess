#include "figure.h"

Figure::Figure (QWidget *parent) : QLabel (parent)
{
    // Центрируем фигуру
    setAlignment(Qt::AlignCenter);
    // Лейбл расширяется по всей доступной площади
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setText ("UNKNOWN_FIGURE");

    //setObjectName ("Figure" + parent->objectName ());
}

Figure::~Figure ()
{

}

void Figure::moveTo (MainWindow *window)
{
    // Логика перемещения
}
