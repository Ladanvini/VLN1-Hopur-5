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
