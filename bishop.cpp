#include "bishop.h"
#include "cell.h"

Bishop::Bishop (Color color, const QVector<QVector<Cell *>> &backfield,
                Cell *parent)
    : Figure (color, backfield, parent)
{
    QPixmap pixmap;
    switch (getColor ())
    {
    case WHITE:
        pixmap.load (":/wFigures/resources/tatiana/wB.png");
        setObjectName ("White_Bishop_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для белого слона не найдено");
        }
        setPixmap (pixmap);
        break;
    case BLACK:
        pixmap.load (":/bFigures/resources/tatiana/bB.png");
        setObjectName ("Black_Bishop_" + parent->objectName ());
        if (pixmap.isNull ())
        {
            throw std::runtime_error("Изображение для чёрного слона не найдено");
        }
        setPixmap (pixmap);
        break;
    default:
        break;
    }
}

Bishop::~Bishop ()
{
}

void Bishop::performActionForWhite ()
{
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

void Bishop::performActionForBlack ()
{
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
