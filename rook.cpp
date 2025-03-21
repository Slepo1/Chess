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
        setObjectName ("White_Rook_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белой ладьи не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        pixmap.load (":/bFigures/resources/tatiana/bR.png");
        setObjectName ("Black_Pawn_" + parent->objectName ());
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
}

void Rook::performActionForBlack ()
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
}

