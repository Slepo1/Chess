#pragma once

#include "figure.h"
#include <QObject>

class Queen : public Figure
{
    Q_OBJECT
public:
    Queen (Color color, const QVector<QVector<Cell *>> &backfield,
           Cell *parent = nullptr);
    ~Queen ();

private:
    // Логика перемещения для белого ферзя
    void performActionForWhite () override;

    // Логика перемещения для чёрного ферзя
    void performActionForBlack () override;
};

