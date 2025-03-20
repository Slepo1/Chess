#include "rook.h"
#include "cell.h"

Rook::Rook (Color color, const QVector<QVector<Cell *>> &backfield,
            Cell *parent)
    : Figure (color, backfield, parent)
{
    QPixmap pixmap;
    switch (getColor ())
    {
    case WHITE:
        pixmap.load (":/wFigures/resources/tatiana/wR.png");
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белой ладьи не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        // Изображение чёрной ладьи
        pixmap.load (":/bFigures/resources/tatiana/bR.png");
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для чёрной ладьи не найдено");
        }
        setPixmap (pixmap);
        break;
    default:
        break;
    }
}

Rook::~Rook ()
{

}

void Rook::performActionForWhite ()
{
    // Пройдемся по строкам вверх
    for (int i = index.row - 1; i >= 0; i--)
    {
        // Проверка на границу клетки
        if (index.row == 0)
            break;


        // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[index.column][i]->
            colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[index.column][i]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[index.column][i]->colorFigure () != Color::NONE))
        {
            m_backfield[index.column][i]->setPossibleCell (true);
            break;
        }

        m_backfield[index.column][i]->setPossibleCell (true);
    }

    // Пройдемся по строкам вниз
    for (int i = index.row + 1; i < 8; i++)
    {
        // Проверка на границу клетки
        if (index.row == 7)
            break;


        // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[index.column][i]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[index.column][i]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[index.column][i]->colorFigure () != Color::NONE))
        {
            m_backfield[index.column][i]->setPossibleCell (true);
            break;
        }

        m_backfield[index.column][i]->setPossibleCell (true);
    }

    // Пройдемся по колоннам вправо
    for (int i = index.column + 1; i < 8; i++)
    {
        // Проверка на границу клетки
        if (index.column == 7)
            break;


        // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][index.row]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][index.row]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][index.row]->colorFigure () != Color::NONE))
        {
            m_backfield[i][index.row]->setPossibleCell (true);
            break;
        }

        m_backfield[i][index.row]->setPossibleCell (true);
    }

           // Пройдемся по колоннам влево
    for (int i = index.column - 1; i >= 0; i--)
    {
        // Проверка на границу клетки
        if (index.column == 0)
            break;


        // Логика если на пути встречаем фигуру(союзную/вражескую)
        if (m_backfield[i][index.row]->colorFigure () == stats.currentColorTurn ())
            break;
        else if ((m_backfield[i][index.row]->colorFigure () != stats.currentColorTurn ()) && (m_backfield[i][index.row]->colorFigure () != Color::NONE))
        {
            m_backfield[i][index.row]->setPossibleCell (true);
            break;
        }

        m_backfield[i][index.row]->setPossibleCell (true);
    }
}

void Rook::performActionForBlack ()
{
    // Пройдемся по строкам вверх
    for (int i = index.row; i > 0; i--)
    {
        m_backfield[index.column][i]->setPossibleCell (true);
    }

           // Пройдемся по строкам вниз
    for (int i = index.row; i < 8; i++)
    {
        m_backfield[index.column][i]->setPossibleCell (true);
    }

           // Пройдемся по колоннам вправо
    for (int i = index.column; i < 8; i++)
    {
        m_backfield[i][index.row]->setPossibleCell (true);
    }

           // Пройдемся по колоннам влево
    for (int i = index.column; i > 0; i--)
    {
        m_backfield[i][index.row]->setPossibleCell (true);
    }
}

