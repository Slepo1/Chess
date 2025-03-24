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

    void getIndexCell () override;

private:
    // Логика перемещения для белой пешки
    void performActionForWhite () override;

    // Логика перемещения для чёрной пешки
    void performActionForBlack () override;

};
