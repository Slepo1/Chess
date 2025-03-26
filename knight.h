#pragma once

#include "figure.h"
#include <QObject>

class Knight : public Figure
{
    Q_OBJECT
public:
    Knight (Color color, const QVector<QVector<Cell *>> &backfield,
             Cell *parent = nullptr);
    ~Knight ();

private:
    // Логика перемещения для белого коня
    void performActionForWhite () override;

    // Логика перемещения для чёрного коня
    void performActionForBlack () override;
};
