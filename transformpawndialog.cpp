#include "transformpawndialog.h"
#include "ui_transformpawndialog.h"

TransformPawnDialog::TransformPawnDialog (Color color, QWidget *parent)
    : QDialog (parent), ui (new Ui::TransformPawnDialog)
{
    ui->setupUi (this);

    m_colorFigure = color;

    if (color == WHITE)
    {
        QIcon icon_wR (":/wFigures/resources/tatiana/wR.png");
        ui->butRook->setIcon (icon_wR);
        QIcon icon_wN (":/wFigures/resources/tatiana/wN.png");
        ui->butKnight->setIcon (icon_wN);
        QIcon icon_wB (":/wFigures/resources/tatiana/wB.png");
        ui->butBishop->setIcon (icon_wB);
        QIcon icon_wQ (":/wFigures/resources/tatiana/wQ.png");
        ui->butQueen->setIcon (icon_wQ);
    }
    else if (color == BLACK)
    {
        QIcon icon_bR(":/wFigures/resources/tatiana/bR.png");
        ui->butRook->setIcon (icon_bR);
        QIcon icon_bN (":/wFigures/resources/tatiana/bN.png");
        ui->butKnight->setIcon (icon_bN);
        QIcon icon_bB (":/wFigures/resources/tatiana/bB.png");
        ui->butBishop->setIcon (icon_bB);
        QIcon icon_bQ (":/wFigures/resources/tatiana/bQ.png");
        ui->butQueen->setIcon (icon_bQ);
    }
}

TransformPawnDialog::~TransformPawnDialog () { delete ui; }

void TransformPawnDialog::on_butRook_clicked()
{
    result = ROOK;
    accept ();
}


void TransformPawnDialog::on_butKnight_clicked()
{
    result = KNIGHT;
    accept ();
}


void TransformPawnDialog::on_butBishop_clicked()
{
    result = BISHOP;
    accept ();
}


void TransformPawnDialog::on_butQueen_clicked()
{
    result = QUEEN;
    accept ();
}

