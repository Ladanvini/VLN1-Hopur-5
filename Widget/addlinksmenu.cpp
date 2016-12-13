#include "addlinksmenu.h"
#include "ui_addlinksmenu.h"

AddLinksMenu::AddLinksMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLinksMenu)
{
    ui->setupUi(this);
}

AddLinksMenu::~AddLinksMenu()
{
    delete ui;
}

void AddLinksMenu::on_pLAdd_clicked()
{
    string PID = ui->input_PID->text().toStdString();
    string CID = ui->input_CID->text().toStdString();

//Check if person id exists
    //TODO

//Check if computer id exists
    //TODO

//creating the person

    _ls.create(PID, CID);
}

void AddLinksMenu::on_pLBack_clicked()
{
    DisplayList dl;
    dl.show();
    this->close();
}
