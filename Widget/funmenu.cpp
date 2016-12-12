#include "funmenu.h"
#include "ui_funmenu.h"

FunMenu::FunMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FunMenu)
{
    ui->setupUi(this);
}

FunMenu::~FunMenu()
{
    delete ui;
}
