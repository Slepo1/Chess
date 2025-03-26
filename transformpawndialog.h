#pragma once


#include <QDialog>
#include "mainwindow.h"

namespace Ui
{
class TransformPawnDialog;
}

class TransformPawnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransformPawnDialog (Color color, QWidget *parent = nullptr);
    ~TransformPawnDialog ();

    ReplacementFig getResult() {return result;}

private slots:
    void on_butRook_clicked();

    void on_butKnight_clicked();

    void on_butBishop_clicked();

    void on_butQueen_clicked();

private:
    Ui::TransformPawnDialog *ui;

    Color m_colorFigure;

    Figure *figure;

    ReplacementFig result;

};

