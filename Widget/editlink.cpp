#include "editlink.h"
#include "ui_editlink.h"

EditLink::EditLink(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditLink)
{
    ui->setupUi(this);
}

EditLink::~EditLink()
{
    delete ui;
}

void EditLink::on_pBEdit_clicked()
{

}

void EditLink::on_pBBack_clicked()
{
    DisplayList dl;
    dl.show();
    this->close();
}
