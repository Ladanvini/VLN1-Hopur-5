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

void SearchMenu::on_pbGoBackPer_clicked()
{
    MainWindow mw;
    mw.show();
    this ->close();
}

void SearchMenu::on_pBGoBackCom_clicked()
{
    MainWindow mw;
    mw.show();
    this ->close();
}
