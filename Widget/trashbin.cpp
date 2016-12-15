#include "trashbin.h"
#include "ui_trashbin.h"

TrashBin::TrashBin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrashBin)
{
    ui->setupUi(this);
}

TrashBin::~TrashBin()
{
    delete ui;
}
