#include "personcreatemenu.h"
#include "ui_personcreatemenu.h"

PersonCreateMenu::PersonCreateMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonCreateMenu)
{
    ui->setupUi(this);
}

PersonCreateMenu::~PersonCreateMenu()
{
    delete ui;
}
