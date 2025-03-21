#include "pawn.h"
#include "cell.h"

Pawn::Pawn (Color color, const QVector<QVector<Cell *>> &backfield,
            Cell *parent) : Figure (color, backfield, parent)
{
    QPixmap pixmap;
    switch (getColor ())
    {
    case WHITE:
        pixmap.load (":/wFigures/resources/tatiana/wP.png");
        setObjectName ("White_Pawn_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белой пешки не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        // Изображение чёрной ладьи
        pixmap.load (":/bFigures/resources/tatiana/bP.png");
        setObjectName ("Black_Pawn_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для чёрной пешки не найдено");
        }
        setPixmap (pixmap);
        break;
    default:
        break;
    }

}

Pawn::~Pawn ()
{
}

void Pawn::performActionForWhite ()
{
    /// Просто по очереди проверим 3 клетки перед пешкой

    // Вверх-слева
    if ((index.row != 0) && (index.column != 0))
    {
        Color chosenCellColor =
            m_backfield[index.row - 1][index.column - 1]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () &&
            chosenCellColor != Color::NONE)
        {
            m_backfield[index.row - 1][index.column - 1]->setPossibleCell (true);
        }
    }

    // Вверх-посередие
    if (index.row != 0)
    {
        Color chosenCellColor = m_backfield[index.row - 1][index.column]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor == Color::NONE)
        {
            m_backfield[index.row - 1][index.column]->setPossibleCell (true);
        }
    }

    // Вверх-справа
    if ((index.row != 0) && (index.column != 7))
    {
        Color chosenCellColor = m_backfield[index.row - 1][index.column + 1]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () &&
            chosenCellColor != Color::NONE)
        {
            m_backfield[index.row - 1][index.column + 1]->setPossibleCell (true);
        }
    }
}

void Pawn::performActionForBlack ()
{
    /// Просто по очереди проверим 3 клетки перед пешкой

    // Вниз-слева
    if ((index.row != 7) && (index.column != 0))
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column - 1]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () &&
            chosenCellColor != Color::NONE)
        {
            m_backfield[index.row + 1][index.column - 1]->setPossibleCell (true);
        }
    }

    // Вниз-посередие
    if (index.row != 7)
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column]->colorFigure ();

        // Проверяем наличие фигуры
        if (chosenCellColor == Color::NONE)
        {
            m_backfield[index.row + 1][index.column]->setPossibleCell (true);
        }
    }

    // Вниз-справа
    if ((index.row != 7) && (index.column != 7))
    {
        Color chosenCellColor = m_backfield[index.row + 1][index.column + 1]->colorFigure ();

               // Проверяем наличие фигуры
        if (chosenCellColor != stats.currentColorTurn () &&
            chosenCellColor != Color::NONE)
        {
            m_backfield[index.row + 1][index.column + 1]->setPossibleCell (true);
        }
    }
}
