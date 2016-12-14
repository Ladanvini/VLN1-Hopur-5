#include "funmenu.h"
#include "ui_funmenu.h"

FunMenu::FunMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FunMenu) {
    ui->setupUi(this);
}

FunMenu::~FunMenu() {
    delete ui;
}

void FunMenu::on_pBUnicorn_clicked() {
    DialogUnicorn Unicorn;
    Unicorn.exec();
    this ->close();
}

void FunMenu::on_pBBack_clicked() {
    MainWindow mw;
    mw.show();
    this ->close();
}
