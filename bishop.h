#pragma once

#include "figure.h"
#include <QObject>

class Bishop : public Figure
{
    Q_OBJECT
public:
    Bishop (Color color, const QVector<QVector<Cell *>> &backfield,
            Cell *parent = nullptr);
    ~Bishop ();

private:
    // Логика перемещения для белого слона
    void performActionForWhite () override;

    // Логика перемещения для чёрного слона
    void performActionForBlack () override;
};

