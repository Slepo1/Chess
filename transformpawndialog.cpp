#include "transformpawndialog.h"
#include "ui_transformpawndialog.h"

TransformPawnDialog::TransformPawnDialog (QWidget *parent)
    : QDialog (parent), ui (new Ui::TransformPawnDialog)
{
    ui->setupUi (this);
}

TransformPawnDialog::~TransformPawnDialog () { delete ui; }
