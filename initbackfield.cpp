#include "mainwindow.h"

// Только чтобы не загромождать кодом mainwindow.cpp логикой инициализации

void MainWindow::setupFigure ()
{
    // Пихаем в указатель на Figure нужный нам тип фигуры с указанием родительского виджета
    whiteFigure[0] = new Rook (Figure::WHITE, backfield, backfield[7][0]);
    whiteFigure[1] = new Figure (Figure::WHITE, backfield, backfield[7][1]);
    whiteFigure[2] = new Figure (Figure::WHITE, backfield, backfield[7][2]);
    whiteFigure[3] = new Figure (Figure::WHITE, backfield, backfield[7][3]);
    whiteFigure[4] = new Figure (Figure::WHITE, backfield, backfield[7][4]);
    whiteFigure[5] = new Figure (Figure::WHITE, backfield, backfield[7][5]);
    whiteFigure[6] = new Figure (Figure::WHITE, backfield, backfield[7][6]);
    whiteFigure[7] = new Rook (Figure::WHITE, backfield, backfield[7][7]);
    whiteFigure[8] = new Figure (Figure::WHITE, backfield, backfield[6][0]);
    whiteFigure[9] = new Figure (Figure::WHITE, backfield, backfield[6][1]);
    whiteFigure[10] = new Figure (Figure::WHITE, backfield, backfield[6][2]);
    whiteFigure[11] = new Figure (Figure::WHITE, backfield, backfield[6][3]);
    whiteFigure[12] = new Figure (Figure::WHITE, backfield, backfield[6][4]);
    whiteFigure[13] = new Figure (Figure::WHITE, backfield, backfield[6][5]);
    whiteFigure[14] = new Figure (Figure::WHITE, backfield, backfield[6][6]);
    whiteFigure[15] = new Figure (Figure::WHITE, backfield, backfield[6][7]);


    //backfield[7][0]->addFig (whiteFigure[0]);
    //backfield[7][7]->addFig (whiteFigure[7]);

}
