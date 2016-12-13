#include "addcomputermenu.h"
#include "ui_addcomputermenu.h"

AddComputerMenu::AddComputerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerMenu)
{
    ui->setupUi(this);
}

AddComputerMenu::~AddComputerMenu()
{
    delete ui;
}

void AddComputerMenu::on_pushButton_clicked()
{
    int id = 0;
    string name = ui->input_Name->text().toStdString();
    string type = ui->input_Type->text().toStdString();
    int yearBuilt = ui->input_YearBuilt->text().toInt();
    bool built = false;

//Checking if built
    if(yearBuilt != 0) {
        built = true;
    }
//creating the person

    _cs.create(id, name, type, yearBuilt, built);

}

void AddComputerMenu::on_pBBack_clicked()
{
    DisplayList dl;
    dl.show();
    this->close();
}
