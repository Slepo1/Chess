#pragma once

#include <QObject>
#include "colors.h"

// Используем Singleton для хранения статистики в единственном экземпляре
class GameStats : public QObject
{
    Q_OBJECT

    GameStats () = default;
    GameStats (const GameStats&) = delete;
    GameStats& operator=(const GameStats&) = delete;

    // Цвет текущего хода
    Color m_currentColorTurn;

    // Номер текущего хода
    int m_numberCurrentTurn;

public:
    static GameStats& getInstance ()
    {
        static GameStats instance;
        return instance;
    }

    Color currentColorTurn () { return m_currentColorTurn; }

    void setCurrentColorTurn (Color color) { m_currentColorTurn = color; }

    int numberCurrentTurn () { return m_numberCurrentTurn; }

    void setNumberCurrentTurn (int number);

    void nextNumberCurrentTurn ();

signals:

    // Обновление ui если изменился счётчик хода
    void changeCountStep();
};

