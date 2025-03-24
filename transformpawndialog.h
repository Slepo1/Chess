#pragma once


#include <QDialog>

namespace Ui
{
class TransformPawnDialog;
}

class TransformPawnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransformPawnDialog (QWidget *parent = nullptr);
    ~TransformPawnDialog ();

private:
    Ui::TransformPawnDialog *ui;
};

