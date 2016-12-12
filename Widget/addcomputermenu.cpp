#include "addcomputermenu.h"
#include "ui_addcomputermenu.h"

AddComputerMenu::AddComputerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddComputerMenu)
{
    ui->setupUi(this);
}

AddComputerMenu::~AddComputerMenu()
{
    delete ui;
}
