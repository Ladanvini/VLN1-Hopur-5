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
    DisplayList dl;
    dl.show();
    this ->close();
}

void AddToDB::on_pBAAddP_clicked()
{
    PersonCreateMenu addP(this);
    addP.exec();
}

void AddToDB::on_pBAAddC_clicked()
{
    AddComputerMenu addC(this);
    addC.exec();
}
