#pragma once

#include <QFrame>
#include <QObject>
#include <QWidget>

class Cell : public QFrame
{
    Q_OBJECT
public:
    Cell (QFrame *&newWidget);

    void newResize ();
};


