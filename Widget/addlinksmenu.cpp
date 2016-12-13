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
