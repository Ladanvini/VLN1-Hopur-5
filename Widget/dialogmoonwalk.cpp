#include "dialogmoonwalk.h"
#include "ui_dialogmoonwalk.h"

DialogMoonWalk::DialogMoonWalk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMoonWalk)
{
    ui->setupUi(this);
}

DialogMoonWalk::~DialogMoonWalk()
{
    delete ui;
}
