#include "addlinksmenu.h"
#include "ui_addlinksmenu.h"

AddLinksMenu::AddLinksMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLinksMenu) {

    ui->setupUi(this);
}

AddLinksMenu::~AddLinksMenu() {
    delete ui;
}

void AddLinksMenu::on_pLAdd_clicked() {

    string PID = ui->input_PID->text().toStdString();
    string CID = ui->input_CID->text().toStdString();

    cout << "PID : " << PID << endl;
    cout << "CID : " << CID << endl;

    //Check if person id exists

    if(!(_ps.checkIDExists(PID)))
        ui->p_error->setText("<span style='color: #ff0000'>ID not found!</span>");
    else
        ui->p_error->setText("<span style='color: #00ff00'>" + QString::fromStdString(_ps.getPersonFromId(stoi(PID)).getName()) + "</span>");

//Check if computer id exists

    if(!(_cs.checkIDExists(CID)))
    {

        ui->c_error->setText("<span style='color: #ff0000'>ID not found!</span>");
    }
    else
    {

        ui->c_error->setText("<span style='color: #00ff00'>" +  QString::fromStdString((_cs.getCompFromId(stoi(CID)).getName())) + "</span>");

    }

//creating the person

    _ls.create(CID, PID);
    DisplayList dll;
    //this->close();
    dll.displayLinks();
}

void AddLinksMenu::on_pLBack_clicked() {
    DisplayList dl;
    dl.show();
    this->close();
}
