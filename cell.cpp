#include "cell.h"

Cell::Cell (QFrame *&newWidget)
{
    // QLabel *fig = new QLabel (this);

    // // Получаем размеры виджета и лейбла
    // int w = this->width();
    // int h = this->height();
    // int lw = fig->sizeHint().width();
    // int lh = fig->sizeHint().height();

    // // Вычисляем центральную позицию
    // int x = (w - lw) / 2;
    // int y = (h - lh) / 2;

    // // Перемещаем лейбл в центр
    // fig->move(x, y);

    // fig->setObjectName("fig" + newWidget->objectName());
    // fig->setText("PRIKOL");

    createLayout ();

    setStyleSheet ("border: 1px solid black;");
}

void Cell::newResize ()
{
    resize (200, 200);
}

void Cell::createLayout ()
{
    horizontalLayout = new QHBoxLayout (this);
    // Устраняем лишние отступы
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    // Центрирование содержимого по горизонтали
    horizontalLayout->setAlignment(Qt::AlignCenter);
    horizontalLayout->setObjectName ("layout" + this->objectName ());
}

QHBoxLayout &Cell::getLayout ()
{
    return *horizontalLayout;
}

bool Cell::checkFig ()
{

    // Поиск внутри Cell'a объекта типа QLabel или его наследников
    QList<QLabel*> labels = this->findChildren<QLabel*>();
    if (!labels.isEmpty())
    {
        // Если есть хоть одна Figure (QLabel)
        qDebug () << "Найден объект типа QLabel или наследник";
        return true;
    }

    return false;
}

void Cell::addFig (Figure *figure)
{
    if (checkFig () == true)
    {
        // Нужно прописать логику в случае на данной клетке уже есть фигура
        return;
    }
    getLayout ().addWidget (figure);
}












/*void Cell::createLayout ()
{



    QHBoxLayout *horizontalLayout = new QHBoxLayout (this);
    horizontalLayout->setObjectName ("layout" + this->objectName());

    QLabel *fig = new QLabel (this);
    fig->setObjectName("fig" + this->objectName());

    horizontalLayout->addWidget(fig);

    fig->setText("PRIKOL");
}*/

