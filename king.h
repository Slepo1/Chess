#pragma once

#include "figure.h"
#include <QObject>

class King : public Figure
{
    Q_OBJECT
public:
    King (Color color, const QVector<QVector<Cell *>> &backfield,
          Cell *parent = nullptr);
    ~King ();

private:

    // Логика перемещения для белого коня
    void performActionForWhite () override;

    // Логика перемещения для чёрного коня
    void performActionForBlack () override;

};

