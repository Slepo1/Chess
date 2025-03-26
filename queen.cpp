#include "queen.h"
#include "cell.h"

Queen::Queen (Color color, const QVector<QVector<Cell *>> &backfield,
              Cell *parent)
    : Figure (color, backfield, parent)
{
    QPixmap pixmap;
    switch (getColor ())
    {
    case WHITE:
        pixmap.load (":/wFigures/resources/tatiana/wQ.png");
        setObjectName ("White_Queen_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белого ферзя не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        pixmap.load (":/bFigures/resources/tatiana/bQ.png");
        setObjectName ("Black_Quenn_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для чёрного ферзя не найдено");
        }
        setPixmap (pixmap);
        break;
    default:
        break;
    }
}

Queen::~Queen ()
{
}

void Queen::performActionForWhite ()
{
    // Пройдемся по строкам вверх
    for (int i = index.row - 1; i >= 0; i--)
    {
        // Проверка на границу клетки
        if (index.row == 0)
            break;


               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][index.column]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][index.column]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][index.column]->colorFigure () != Color::NONE))
        {
            m_backfield[i][index.column]->setPossibleCell (true);
            break;
        }

        m_backfield[i][index.column]->setPossibleCell (true);
    }

           // Пройдемся по строкам вниз
    for (int i = index.row + 1; i < 8; i++)
    {
        // Проверка на границу клетки
        if (index.row == 7)
            break;


               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][index.column]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][index.column]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][index.column]->colorFigure () != Color::NONE))
        {
            m_backfield[i][index.column]->setPossibleCell (true);
            break;
        }

        m_backfield[i][index.column]->setPossibleCell (true);
    }

           // Пройдемся по колоннам вправо
    for (int i = index.column + 1; i < 8; i++)
    {
        // Проверка на границу клетки
        if (index.column == 7)
            break;


               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[index.row][i]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[index.row][i]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[index.row][i]->colorFigure () != Color::NONE))
        {
            m_backfield[index.row][i]->setPossibleCell (true);
            break;
        }

        m_backfield[index.row][i]->setPossibleCell (true);
    }

           // Пройдемся по колоннам влево
    for (int i = index.column - 1; i >= 0; i--)
    {
        // Проверка на границу клетки
        if (index.column == 0)
            break;


               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[index.row][i]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[index.row][i]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[index.row][i]->colorFigure () != Color::NONE))
        {
            m_backfield[index.row][i]->setPossibleCell (true);
            break;
        }

        m_backfield[index.row][i]->setPossibleCell (true);
    }

    /// Сверху логика ладьи, снизу слона

    // Пройдемся вверх-влево
    for (int i = index.row - 1, j = index.column - 1; i >= 0 && j >= 0; i--, j--)
    {
        // Проверка на границу клетки
        if (index.row == 0 && index.column == 0)
            break;


               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][j]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][j]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][j]->colorFigure () != Color::NONE))
        {
            m_backfield[i][j]->setPossibleCell (true);
            break;
        }

        m_backfield[i][j]->setPossibleCell (true);
    }

           // Пройдемся вверх-вправо
    for (int i = index.row - 1, j = index.column + 1; i >= 0 && j < 8; i--, j++)
    {
        // Проверка на границу клетки
        if (index.row == 0 && index.column == 7)
            break;

               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][j]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][j]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][j]->colorFigure () != Color::NONE))
        {
            m_backfield[i][j]->setPossibleCell (true);
            break;
        }

        m_backfield[i][j]->setPossibleCell (true);
    }

           // Пройдемся вниз-влево
    for (int i = index.row + 1, j = index.column - 1; i < 8 && j >= 0; i++, j--)
    {
        // Проверка на границу клетки
        if (index.row == 7 && index.column == 0)
            break;

               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][j]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][j]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][j]->colorFigure () != Color::NONE))
        {
            m_backfield[i][j]->setPossibleCell (true);
            break;
        }

        m_backfield[i][j]->setPossibleCell (true);
    }

           // Пройдемся вниз-вправо
    for (int i = index.row + 1, j = index.column + 1; i < 8 && j < 8; i++, j++)
    {
        // Проверка на границу клетки
        if (index.row == 7 && index.column == 7)
            break;

               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][j]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][j]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][j]->colorFigure () != Color::NONE))
        {
            m_backfield[i][j]->setPossibleCell (true);
            break;
        }

        m_backfield[i][j]->setPossibleCell (true);
    }

}

void Queen::performActionForBlack ()
{
    // Пройдемся по строкам вверх
    for (int i = index.row - 1; i >= 0; i--)
    {
        // Проверка на границу клетки
        if (index.row == 0)
            break;


               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][index.column]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if (m_backfield[i][index.column]->colorFigure () !=
                     stats.currentColorTurn () &&
                 m_backfield[i][index.column]->colorFigure () != Color::NONE)
        {
            m_backfield[i][index.column]->setPossibleCell (true);
            break;
        }

        m_backfield[i][index.column]->setPossibleCell (true);
    }

           // Пройдемся по строкам вниз
    for (int i = index.row + 1; i < 8; i++)
    {
        // Проверка на границу клетки
        if (index.row == 7)
            break;


               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][index.column]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][index.column]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][index.column]->colorFigure () != Color::NONE))
        {
            m_backfield[i][index.column]->setPossibleCell (true);
            break;
        }

        m_backfield[i][index.column]->setPossibleCell (true);
    }

           // Пройдемся по колоннам вправо
    for (int i = index.column + 1; i < 8; i++)
    {
        // Проверка на границу клетки
        if (index.column == 7)
            break;


               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[index.row][i]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[index.row][i]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[index.row][i]->colorFigure () != Color::NONE))
        {
            m_backfield[index.row][i]->setPossibleCell (true);
            break;
        }

        m_backfield[index.row][i]->setPossibleCell (true);
    }

           // Пройдемся по колоннам влево
    for (int i = index.column - 1; i >= 0; i--)
    {
        // Проверка на границу клетки
        if (index.column == 0)
            break;

               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[index.row][i]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[index.row][i]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[index.row][i]->colorFigure () != Color::NONE))
        {
            m_backfield[index.row][i]->setPossibleCell (true);
            break;
        }

        m_backfield[index.row][i]->setPossibleCell (true);
    }

    /// Сверху логика ладьи, снизу слона

    // Пройдемся вверх-влево
    for (int i = index.row - 1, j = index.column - 1; i >= 0 && j >= 0; i--, j--)
    {
        // Проверка на границу клетки
        if (index.row == 0 && index.column == 0)
            break;

               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][j]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][j]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][j]->colorFigure () != Color::NONE))
        {
            m_backfield[i][j]->setPossibleCell (true);
            break;
        }

        m_backfield[i][j]->setPossibleCell (true);
    }

           // Пройдемся вверх-вправо
    for (int i = index.row - 1, j = index.column + 1; i >= 0 && j < 8; i--, j++)
    {
        // Проверка на границу клетки
        if (index.row == 0 && index.column == 7)
            break;

               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][j]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][j]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][j]->colorFigure () != Color::NONE))
        {
            m_backfield[i][j]->setPossibleCell (true);
            break;
        }

        m_backfield[i][j]->setPossibleCell (true);
    }

           // Пройдемся вниз-влево
    for (int i = index.row + 1, j = index.column - 1; i < 8 && j >= 0; i++, j--)
    {
        // Проверка на границу клетки
        if (index.row == 7 && index.column == 0)
            break;

               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][j]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][j]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][j]->colorFigure () != Color::NONE))
        {
            m_backfield[i][j]->setPossibleCell (true);
            break;
        }

        m_backfield[i][j]->setPossibleCell (true);
    }

           // Пройдемся вниз-вправо
    for (int i = index.row + 1, j = index.column + 1; i < 8 && j < 8; i++, j++)
    {
        // Проверка на границу клетки
        if (index.row == 7 && index.column == 7)
            break;

               // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][j]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][j]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][j]->colorFigure () != Color::NONE))
        {
            m_backfield[i][j]->setPossibleCell (true);
            break;
        }

        m_backfield[i][j]->setPossibleCell (true);
    }
}

