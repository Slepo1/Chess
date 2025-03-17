#include "gamestats.h"

void GameStats::setNumberCurrentTurn (int number)
{
    m_numberCurrentTurn = number;

    // Раз меняем значение счётчика хода, пора бы обновить GUI
    emit changeCountStep ();
}

void GameStats::nextNumberCurrentTurn ()
{
    m_numberCurrentTurn++;

    // Раз меняем значение счётчика хода, пора бы обновить GUI
    emit changeCountStep ();
}
