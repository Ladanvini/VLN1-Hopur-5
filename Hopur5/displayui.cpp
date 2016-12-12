#include "displayui.h"
#include "ui_displayui.h"

DisplayUi::DisplayUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayUi)
{
    ui->setupUi(this);
}

DisplayUi::~DisplayUi()
{
    delete ui;
}
