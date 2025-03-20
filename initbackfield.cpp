#include "mainwindow.h"

// Только чтобы не загромождать кодом mainwindow.cpp логикой инициализации

void MainWindow::setupFigure ()
{
    // Пихаем в указатель на Figure нужный нам тип фигуры с указанием родительского виджета

    // Белые фигуры
    whiteFigure[0] = new Rook (Color::WHITE, backfield, backfield[7][0]);
    whiteFigure[1] = new Figure (Color::WHITE, backfield, backfield[7][1]);
    whiteFigure[2] = new Figure (Color::WHITE, backfield, backfield[7][2]);
    whiteFigure[3] = new Figure (Color::WHITE, backfield, backfield[7][3]);
    whiteFigure[4] = new Figure (Color::WHITE, backfield, backfield[7][4]);
    whiteFigure[5] = new Figure (Color::WHITE, backfield, backfield[7][5]);
    whiteFigure[6] = new Figure (Color::WHITE, backfield, backfield[7][6]);
    whiteFigure[7] = new Rook (Color::WHITE, backfield, backfield[7][7]);
    whiteFigure[8] = new Pawn (Color::WHITE, backfield, backfield[6][0]);
    whiteFigure[9] = new Pawn (Color::WHITE, backfield, backfield[6][1]);
    whiteFigure[10] = new Pawn (Color::WHITE, backfield, backfield[6][2]);
    whiteFigure[11] = new Pawn (Color::WHITE, backfield, backfield[6][3]);
    whiteFigure[12] = new Pawn (Color::WHITE, backfield, backfield[6][4]);
    whiteFigure[13] = new Pawn (Color::WHITE, backfield, backfield[6][5]);
    whiteFigure[14] = new Pawn (Color::WHITE, backfield, backfield[6][6]);
    whiteFigure[15] = new Pawn (Color::WHITE, backfield, backfield[6][7]);


    // Чёрные фигуры
    blackFigure[0] = new Rook (Color::BLACK, backfield, backfield[0][0]);
    blackFigure[1] = new Figure (Color::BLACK, backfield, backfield[0][1]);
    blackFigure[2] = new Figure (Color::BLACK, backfield, backfield[0][2]);
    blackFigure[3] = new Figure (Color::BLACK, backfield, backfield[0][3]);
    blackFigure[4] = new Figure (Color::BLACK, backfield, backfield[0][4]);
    blackFigure[5] = new Figure (Color::BLACK, backfield, backfield[0][5]);
    blackFigure[6] = new Figure (Color::BLACK, backfield, backfield[0][6]);
    blackFigure[7] = new Rook (Color::BLACK, backfield, backfield[0][7]);
    blackFigure[8] = new Pawn (Color::BLACK, backfield, backfield[1][0]);
    blackFigure[9] = new Pawn (Color::BLACK, backfield, backfield[1][1]);
    blackFigure[10] = new Pawn (Color::BLACK, backfield, backfield[1][2]);
    blackFigure[11] = new Pawn (Color::BLACK, backfield, backfield[1][3]);
    blackFigure[12] = new Pawn (Color::BLACK, backfield, backfield[1][4]);
    blackFigure[13] = new Pawn (Color::BLACK, backfield, backfield[1][5]);
    blackFigure[14] = new Pawn (Color::BLACK, backfield, backfield[1][6]);
    blackFigure[15] = new Pawn (Color::BLACK, backfield, backfield[1][7]);
}
