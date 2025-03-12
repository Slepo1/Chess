#pragma once

#include "figure.h"
#include <QObject>

class Rook : public Figure
{
    Q_OBJECT
public:
    Rook (QWidget *parent = nullptr);
    ~Rook ();

    void moveTo (MainWindow *window) override;
};
