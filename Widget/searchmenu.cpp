#include "searchmenu.h"
#include "ui_searchmenu.h"

SearchMenu::SearchMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchMenu)
{
    ui->setupUi(this);
}

SearchMenu::~SearchMenu()
{
    delete ui;
}
