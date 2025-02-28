#pragma once

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>

class Cell : public QFrame
{
    Q_OBJECT

    void createLayout ();

    QHBoxLayout *horizontalLayout;

    bool checkFig (QPoint point);

    //void mousePressEvent (QMouseEvent *event) override;


public:
    Cell (QFrame *&newWidget);

    void newResize ();

    QHBoxLayout &getLayout ();
};


