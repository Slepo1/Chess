#pragma once

#include <QLabel>
#include <QObject>

class Figure : public QLabel
{
    Q_OBJECT
public:
    Figure (QWidget *parent = nullptr);
    virtual ~Figure();

    virtual void moveTo (const QPoint newPosition);
};


