#pragma once

#include "figure.h"
#include <QObject>

class Rook : public Figure
{
    Q_OBJECT
public:
    Rook (Color color, const QVector<QVector<Cell *>> &backfield,
          Cell *parent = nullptr);
    ~Rook ();

private:
    // Логика перемещения для белой ладьи
    void performActionForWhite () override;

    // Логика перемещения для чёрной ладьи
    void performActionForBlack () override;
};
