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

    ui->l_error_name->setText("");
    ui->l_error_type->setText("");
    ui->l_error_yearBuilt->setText("");
//Error checks
    if(name.empty()) {
        ui->l_error_name->setText("<span style='color: #ff0000'>Name not accepted!</span>");

        if(type.empty()) {
            ui->l_error_type->setText("<span style='color: #ff0000'>Type not accepted!</span>");

            if(yearBuiltstr.empty() || !isOK) {
                ui->l_error_yearBuilt->setText("<span style='color: #ff0000'>Year not accepted!</span>");
            }
        }
        return;
    }

    if(type.empty()){
        ui->l_error_type->setText("<span style='color: #ff0000'>Type not accepted!</span>");

        if(yearBuiltstr.empty() || !isOK) {
            ui->l_error_yearBuilt->setText("<span style='color: #ff0000'>Year not accepted!</span>");
        }
        return;
    }

    if(yearBuiltstr.empty() || !isOK){
        ui->l_error_yearBuilt->setText("<span style='color: #ff0000'>Year not accepted!</span>");
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
