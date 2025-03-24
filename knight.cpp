#include "knight.h"
#include "cell.h"

Knight::Knight (Color color, const QVector<QVector<Cell *>> &backfield,
                Cell *parent) : Figure (color, backfield, parent)
{
    QPixmap pixmap;
    switch (getColor ())
    {
    case WHITE:
        pixmap.load (":/wFigures/resources/tatiana/wN.png");
        setObjectName ("White_Knight_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белого коня не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        pixmap.load (":/bFigures/resources/tatiana/bN.png");
        setObjectName ("Black_Knight_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для чёрного коня не найдено");
        }
        setPixmap (pixmap);
        break;
    default:
        break;
    }

}

Knight::~Knight ()
{
}

void Knight::performActionForWhite ()
{
    /// Будем проверять поочередно каждую из 8 клеток для передвижения

    // Вверх-вверх-влево
    if ((index.row > 1) && (index.column != 0))
    {
        Color chosenCellColor =
            m_backfield[index.row - 2][index.column - 1]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            (chosenCellColor == Color::NONE))
        {
            m_backfield[index.row - 2][index.column - 1]->setPossibleCell (
                true);
        }
    }

    // Вверх-вверх-справа
    if ((index.row > 1) && (index.column != 7))
    {
        Color chosenCellColor =
            m_backfield[index.row - 2][index.column + 1]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            (chosenCellColor == Color::NONE))
        {
            m_backfield[index.row - 2][index.column + 1]->setPossibleCell (
                true);
        }
    }

    // Слева-слева-вверх
    if ((index.row != 0) && (index.column > 1))
    {
        Color chosenCellColor =
            m_backfield[index.row - 1][index.column - 2]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column - 2]->setPossibleCell (
                true);
        }
    }

    // Справа-справа-вверх
    if (index.row != 0 && index.column < 6)
    {
        Color chosenCellColor =
            m_backfield[index.row - 1][index.column + 2]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column + 2]->setPossibleCell (
                true);
        }
    }

    // Слева-слева-вниз
    if (index.row != 7 && index.column > 1)
    {
        Color chosenCellColor =
            m_backfield[index.row + 1][index.column - 2]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column - 2]->setPossibleCell (
                true);
        }
    }

    // Справа-справа-вниз
    if (index.row != 7 && index.column < 6)
    {
        Color chosenCellColor =
            m_backfield[index.row + 1][index.column + 2]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column + 2]->setPossibleCell (
                true);
        }
    }

    // Вниз-вниз-влево
    if (index.row < 6 && index.column != 0)
    {
        Color chosenCellColor =
            m_backfield[index.row + 2][index.column - 1]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 2][index.column - 1]->setPossibleCell (
                true);
        }
    }

    // Вниз-вниз-вправо
    if (index.row < 6 && index.column != 7)
    {
        Color chosenCellColor =
            m_backfield[index.row + 2][index.column + 1]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 2][index.column + 1]->setPossibleCell (
                true);
        }
    }
}

void Knight::performActionForBlack ()
{
    /// Будем проверять поочередно каждую из 8 клеток для передвижения

    // Вверх-вверх-влево
    if ((index.row > 1) && (index.column != 0))
    {
        Color chosenCellColor =
            m_backfield[index.row - 2][index.column - 1]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            (chosenCellColor == Color::NONE))
        {
            m_backfield[index.row - 2][index.column - 1]->setPossibleCell (
                true);
        }
    }

    // Вверх-вверх-справа
    if ((index.row > 1) && (index.column != 7))
    {
        Color chosenCellColor =
            m_backfield[index.row - 2][index.column + 1]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            (chosenCellColor == Color::NONE))
        {
            m_backfield[index.row - 2][index.column + 1]->setPossibleCell (
                true);
        }
    }

    // Слева-слева-вверх
    if ((index.row != 0) && (index.column > 1))
    {
        Color chosenCellColor =
            m_backfield[index.row - 1][index.column - 2]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column - 2]->setPossibleCell (
                true);
        }
    }

    // Справа-справа-вверх
    if (index.row != 0 && index.column < 6)
    {
        Color chosenCellColor =
            m_backfield[index.row - 1][index.column + 2]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column + 2]->setPossibleCell (
                true);
        }
    }

    // Слева-слева-вниз
    if (index.row != 7 && index.column > 1)
    {
        Color chosenCellColor =
            m_backfield[index.row + 1][index.column - 2]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column - 2]->setPossibleCell (
                true);
        }
    }

    // Справа-справа-вниз
    if (index.row != 7 && index.column < 6)
    {
        Color chosenCellColor =
            m_backfield[index.row + 1][index.column + 2]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column + 2]->setPossibleCell (
                true);
        }
    }

    // Вниз-вниз-влево
    if (index.row < 6 && index.column != 0)
    {
        Color chosenCellColor =
            m_backfield[index.row + 2][index.column - 1]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 2][index.column - 1]->setPossibleCell (
                true);
        }
    }

    // Вниз-вниз-вправо
    if (index.row < 6 && index.column != 7)
    {
        Color chosenCellColor =
            m_backfield[index.row + 2][index.column + 1]->colorFigure ();

        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 2][index.column + 1]->setPossibleCell (
                true);
        }
    }
}
