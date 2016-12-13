#include "addtodb.h"
#include "ui_addtodb.h"

AddToDB::AddToDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDB)
{
    ui->setupUi(this);
}

AddToDB::~AddToDB()
{
    delete ui;
}

void AddToDB::on_pBABack_clicked()
{
    MainWindow mw;
    mw.show();
    this ->close();
}
