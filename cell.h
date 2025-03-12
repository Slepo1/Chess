#pragma once

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>
#include "figure.h"

class Cell : public QFrame
{
    Q_OBJECT

    void createLayout ();

    QHBoxLayout *horizontalLayout;

    bool checkFig ();

    //void mousePressEvent (QMouseEvent *event) override;

    QHBoxLayout &getLayout ();

public:
    Cell (QFrame *&newWidget);

    void newResize ();

    // Метод лучше оставить отдельный, тк будем проверять checkfig заполненность клетки
    void addFig (Figure *figure);

};


