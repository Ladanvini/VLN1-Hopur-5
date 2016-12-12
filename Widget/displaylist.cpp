#include "displaylist.h"
#include "ui_displaylist.h"

DisplayList::DisplayList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayList)
{
    ui->setupUi(this);
}

DisplayList::~DisplayList()
{
    delete ui;
}
