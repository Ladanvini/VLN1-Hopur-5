#include "editperson.h"
#include "ui_editperson.h"

editPerson::editPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPerson)
{
    ui->setupUi(this);
}

editPerson::~editPerson()
{
    delete ui;
}

void editPerson::on_pBEdit_clicked()
{

}

void editPerson::on_pBCancel_clicked()
{

}
