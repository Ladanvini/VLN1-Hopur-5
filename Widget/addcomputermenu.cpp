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

void AddComputerMenu::on_pBAdd_clicked()
{
    int id = 0;
    bool isOK = false;
    string name = ui->input_Name->text().toStdString();
    string type = ui->input_Type->text().toStdString();
    string yearBuiltstr = ui->input_YearBuilt->text().toStdString();
    int yearBuilt = ui->input_YearBuilt->text().toInt(&isOK);
    bool built = false;

//Checking if built
    if(yearBuilt != 0) {
        built = true;
    }
//Error checks
    if(name.empty()) {
        //ERROR MESSAGE
        return;
    }
    if(type.empty()) {
        //ERROR
        return;
    }
    if(yearBuiltstr.empty() || !isOK){
        //ERRROR
        return;
    }


//creating the computer

    _cs.create(id, name, type, yearBuilt, built);



    DisplayList dlc;

    this->close();

    dlc.displayComps();

}

void AddComputerMenu::on_pBBack_clicked()
{
    DisplayList dl;
    dl.show();
    this->close();

    dl.displayComps();
}
