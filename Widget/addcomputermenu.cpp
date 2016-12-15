#include "addcomputermenu.h"
#include "ui_addcomputermenu.h"

AddComputerMenu::AddComputerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerMenu) {
/*    _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    _cs = CompService(_dbpath);
    _ps = appservice(_dbpath);
    _ls = LinkService(_dbpath);
*/
    ui->setupUi(this);
}

AddComputerMenu::~AddComputerMenu() {
    delete ui;
}

void AddComputerMenu::on_pBAdd_clicked() {
    int id = 0;
    bool isOK = false;
    string name = ui->input_Name->text().toStdString();
    string type = ui->input_Type->text().toStdString();
    string yearBuiltstr = ui->input_YearBuilt->text().toStdString();
    int yearBuilt = ui->input_YearBuilt->text().toInt(&isOK);
    bool built = false;

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t);
    int currYear = (now->tm_year + 1900);

//Checking if built
    if(yearBuilt != 0) {
        built = true;
    }

    if(yearBuiltstr.empty()) {
        built = false;
        yearBuilt = 0;
        isOK = true;
    }

    ui->l_error_name->setText("");
    ui->l_error_type->setText("");
    ui->l_error_yearBuilt->setText("");

//Error checks
    if(name.empty() || name.at(0) == ' ') {
        ui->l_error_name->setText("<span style='color: #ff0000'>Name not accepted!</span>");

        if(type.empty() || type.at(0) == ' ') {
            ui->l_error_type->setText("<span style='color: #ff0000'>Type not accepted!</span>");

            if(!isOK || yearBuilt > currYear || (yearBuilt < 100 && yearBuilt != 0)) {
                ui->l_error_yearBuilt->setText("<span style='color: #ff0000'>Year not accepted!</span>");
            }
        }
        return;
    }

    if(type.empty() || type.at(0) == ' ') {
        ui->l_error_type->setText("<span style='color: #ff0000'>Type not accepted!</span>");

        if(!isOK || yearBuilt > currYear || (yearBuilt < 100 && yearBuilt != 0)) {
            ui->l_error_yearBuilt->setText("<span style='color: #ff0000'>Year not accepted!</span>");
        }
        return;
    }

    if(!isOK || yearBuilt > currYear || (yearBuilt < 100 && yearBuilt != 0)) {
        ui->l_error_yearBuilt->setText("<span style='color: #ff0000'>Year not accepted!</span>");
        return;
    }

//creating the computer
    _cs.create(id, name, type, yearBuilt, built);

    DisplayList dlc;
    this->close();
    dlc.displayComps();
}

void AddComputerMenu::on_pBBack_clicked() {
    DisplayList dl;
    dl.show();
    this->close();
    dl.displayComps();
}
