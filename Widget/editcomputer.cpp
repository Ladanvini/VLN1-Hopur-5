#include "editcomputer.h"
#include "ui_editcomputer.h"

editComputer::editComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputer) {
    ui->setupUi(this);
}

editComputer::~editComputer() {
    delete ui;
}


void editComputer::on_pBBack_clicked()
{
    DisplayList dl;
    dl.show();
    this->close();
}

void editComputer::on_pBAdd_clicked()
{
   /* int id = 0;
    int year = ui->input_YearBuilt->text().toInt();
    string type = ui->input_Type->text().toStdString();
    string name = ui->input_Name->text().toStdString();
    _cs.editComputerWith(id, name, type, year);*/

    DisplayList dl;
    dl.show();
    this->close();
}
