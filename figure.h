#ifndef FIGURE_H
#define FIGURE_H

#include <QLabel>
#include <QObject>

class Figure : public QLabel
{
    Q_OBJECT
public:
    Figure (QLabel *&fig);
};

#endif // FIGURE_H
