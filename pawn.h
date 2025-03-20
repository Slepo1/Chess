#pragma once

#include "figure.h"
#include <QObject>

class Pawn : public Figure
{
    Q_OBJECT
public:
    Pawn (Color color, const QVector<QVector<Cell *>> &backfield,
          Cell *parent = nullptr);
    ~Pawn ();

private:
    // Логика перемещения для белой ладьи
    void performActionForWhite () override;

    // Логика перемещения для чёрной ладьи
    void performActionForBlack () override;
};
