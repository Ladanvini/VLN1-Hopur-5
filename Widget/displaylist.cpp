#include "displaylist.h"
#include "ui_displaylist.h"

DisplayList::DisplayList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayList)
{
    ui->setupUi(this);
}

DisplayList::~DisplayList()
{
    delete ui;
}

void DisplayList::on_pBPBack_clicked()
{
    MainWindow mw;
    mw.show();
    this ->close();
}
