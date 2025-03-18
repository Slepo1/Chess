#include "cell.h"

Cell::Cell (QFrame *parent) : QFrame (parent), stats (GameStats::getInstance ())
{
    createLayout ();

    setStyleSheet ("border: 1px solid black;");


}

void Cell::newResize ()
{
    //resize (200, 200);
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
        // Нужно прописать логику в случае если на данной клетке уже есть фигура
        return;
    }
    getLayout ().addWidget (figure);
}

void Cell::setPossibleCell (bool possible)
{
    // Здесь надо прописать логику, если на клетке присутствует дружественная/вражеская фигура
    if (checkFig () == true)
    {
        // Проверяем принадлежность по цвету с цветом текущего хода
        if (colorFigure () == stats.currentColorTurn ())
        {
            // Союзная фигура на клетке
            return;
        }
        else
        {

        }
    }


    //setStyleSheet("background-color: red;");

    m_possible = possible;
    if (m_possible)
    {
        // qss сказал мне идти нахуй, поэтому будем делать через setStyleSheet
        setStyleSheet("background-color: green;");

    }
    else
    {
        // qss сказал мне идти нахуй, поэтому будем делать через setStyleSheet
        setStyleSheet(baseStyleSheet);

    }

}

Color Cell::colorFigure ()
{

    // Поиск внутри Cell'a объекта типа QLabel или его наследников
    QList<Figure*> figures = this->findChildren<Figure*>();
    if (figures.isEmpty())
    {
        // Если нет Figure (QLabel)
        qDebug () << "Не найдена фигура в клетке";
        return Color::NONE;
    }
    return figures[0]->getColor ();

}

void Cell::saveStyleSheet ()
{
    baseStyleSheet = styleSheet ();
}

void Cell::setBaseStyleSheet ()
{
    setStyleSheet (baseStyleSheet);
}
