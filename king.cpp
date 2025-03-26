#include "king.h"
#include "cell.h"

King::King (Color color, const QVector<QVector<Cell *>> &backfield,
            Cell *parent) : Figure (color, backfield, parent)
{
    QPixmap pixmap;
    switch (getColor ())
    {
    case WHITE:
        pixmap.load (":/wFigures/resources/tatiana/wK.png");
        setObjectName ("White_King_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белого короля не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        pixmap.load (":/bFigures/resources/tatiana/bK.png");
        setObjectName ("Black_King_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для чёрного короля не найдено");
        }
        setPixmap (pixmap);
        break;
    default:
        break;
    }
}

King::~King ()
{}

void King::performActionForWhite ()
{
    // Вверх-слева
    if ((index.row != 0) && (index.column != 0))
    {
        Color chosenCellColor = m_backfield[index.row - 1][index.column - 1]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column - 1]->setPossibleCell (true);
        }
    }

    // Вверх
    if (index.row != 0)
    {
        Color chosenCellColor = m_backfield[index.row - 1][index.column]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column]->setPossibleCell (true);
        }
    }

    // Вверх-справа
    if ((index.row != 0) && (index.column != 7))
    {
        Color chosenCellColor = m_backfield[index.row - 1][index.column + 1]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column + 1]->setPossibleCell (true);
        }
    }

    // Влево
    if (index.column != 0)
    {
        Color chosenCellColor =
            m_backfield[index.row][index.column - 1]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row][index.column - 1]->setPossibleCell (true);
        }
    }

    // Вправо
    if (index.column != 7)
    {
        Color chosenCellColor =
            m_backfield[index.row][index.column + 1]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row][index.column + 1]->setPossibleCell (true);
        }
    }

    // Вниз-влево
    if ((index.row != 7) && (index.column != 0))
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column - 1]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column - 1]->setPossibleCell (true);
        }
    }

    // Вниз
    if (index.row != 7)
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column]->setPossibleCell (true);
        }
    }

    // Вниз-вправо
    if ((index.row != 7) && (index.column != 7))
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column + 1]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column + 1]->setPossibleCell (true);
        }
    }
}

void King::performActionForBlack ()
{
    // Вверх-слева
    if ((index.row != 0) && (index.column != 0))
    {
        Color chosenCellColor = m_backfield[index.row - 1][index.column - 1]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column - 1]->setPossibleCell (true);
        }
    }

           // Вверх
    if (index.row != 0)
    {
        Color chosenCellColor = m_backfield[index.row - 1][index.column]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column]->setPossibleCell (true);
        }
    }

           // Вверх-справа
    if ((index.row != 0) && (index.column != 7))
    {
        Color chosenCellColor = m_backfield[index.row - 1][index.column + 1]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column + 1]->setPossibleCell (true);
        }
    }

           // Влево
    if (index.column != 0)
    {
        Color chosenCellColor =
            m_backfield[index.row][index.column - 1]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row][index.column - 1]->setPossibleCell (true);
        }
    }

           // Вправо
    if (index.column != 7)
    {
        Color chosenCellColor =
            m_backfield[index.row][index.column + 1]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row][index.column + 1]->setPossibleCell (true);
        }
    }

           // Вниз-влево
    if ((index.row != 7) && (index.column != 0))
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column - 1]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column - 1]->setPossibleCell (true);
        }
    }

           // Вниз
    if (index.row != 7)
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column]->setPossibleCell (true);
        }
    }

           // Вниз-вправо
    if ((index.row != 7) && (index.column != 7))
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column + 1]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () ||
            chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column + 1]->setPossibleCell (true);
        }
    }
}
