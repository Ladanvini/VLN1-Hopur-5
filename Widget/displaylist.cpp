#include "displaylist.h"
#include "ui_displaylist.h"

DisplayList::DisplayList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayList)
{
    ui->setupUi(this);
}

DisplayList::~DisplayList()
{
    delete ui;
}
