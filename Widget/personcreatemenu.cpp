#include "personcreatemenu.h"
#include "ui_personcreatemenu.h"

PersonCreateMenu::PersonCreateMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonCreateMenu)
{
    ui->setupUi(this);
}

PersonCreateMenu::~PersonCreateMenu()
{
    delete ui;
}
