#pragma once

#include <QLabel>
#include <QObject>

// Предварительное объявление
class MainWindow;

class Figure : public QLabel
{
    Q_OBJECT
public:
    Figure (QWidget *parent = nullptr);
    virtual ~Figure();

    virtual void moveTo (MainWindow *window);
};


