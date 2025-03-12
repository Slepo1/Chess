#include "mainwindow.h"

// Только чтобы не загромождать кодом mainwindow.cpp логикой инициализации

void MainWindow::setupFigure ()
{
    // Пихаем в указатель на Figure нужный нам тип фигуры
    whiteFigure[0] = new Rook (nullptr);
    whiteFigure[1] = new Figure (nullptr);
    whiteFigure[2] = new Figure (nullptr);
    whiteFigure[3] = new Figure (nullptr);
    whiteFigure[4] = new Figure (nullptr);
    whiteFigure[5] = new Figure (nullptr);
    whiteFigure[6] = new Figure (nullptr);
    whiteFigure[7] = new Figure (nullptr);
    whiteFigure[8] = new Rook (nullptr);
    whiteFigure[9] = new Figure (nullptr);
    whiteFigure[10] = new Figure (nullptr);
    whiteFigure[11] = new Figure (nullptr);
    whiteFigure[12] = new Figure (nullptr);
    whiteFigure[13] = new Figure (nullptr);
    whiteFigure[14] = new Figure (nullptr);
    whiteFigure[15] = new Figure (nullptr);

    backfield[7][0]->addFig (whiteFigure[0]);
    backfield[7][7]->addFig (whiteFigure[8]);


    /*for (int i = 0; i < whiteFigure.size (); i++)
    {
        backfield[i / 8][i % 8]->addFig (whiteFigure[i]);
    }*/
}
