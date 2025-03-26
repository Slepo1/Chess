#include "cell.h"

Cell::Cell (QFrame *parent) : QFrame (parent), stats (GameStats::getInstance ())
{
    createLayout ();

    setStyleSheet ("border: 1px solid black;");

    // Задаем фиксированный размер Cell
    fixedResize ();
}

Cell::~Cell ()
{

}

void Cell::fixedResize ()
{

    setMinimumHeight (84);
    setMinimumWidth (101);

    setMaximumHeight (84);
    setMaximumWidth (101);
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
        qDebug () << "Найден объект типа QLabel или наследник в клетке " + objectName ();
        return true;
    }

    return false;
}

void Cell::addFig (Figure *figure)
{
    if (checkFig ())
    {
        // Клетка занята
        return;
    }

    getLayout ().addWidget (figure);
}

void Cell::removeFig (Figure *figure)
{
    if (!checkFig ())
    {
        // Клетка свободна
        return;
    }

    getLayout().removeWidget(figure);

    figure->setParent (nullptr);
}

void Cell::setPossibleCell (bool possible)
{
    // Хотим сделать клетку доступной для хода, но нужно проверить какого цвета фигура на ней
    if (possible == true)
    {
        if (checkFig () == true)
        {
            // Проверяем принадлежность по цвету с цветом текущего хода
            if (colorFigure () == stats.currentColorTurn ())
            {
                // Союзная фигура на клетке
                return;
            }
        }
    }


    m_possible = possible;
    if (m_possible)
    {
        // qss сказал мне идти нахуй, поэтому будем делать через setStyleSheet
        setStyleSheet ("background-color: green;");
    }
    else
    {
        // Перекрашиваем обратно зеленные клетки в базовый цвет
        setBaseStyleSheet ();
    }
}

Color Cell::colorFigure ()
{

    // Поиск внутри Cell'a объекта типа QLabel или его наследников
    QList<Figure*> figures = this->findChildren<Figure*>();
    if (figures.isEmpty())
    {
        // Если нет Figure (QLabel)
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
