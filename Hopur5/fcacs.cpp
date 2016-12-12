#include "fcacs.h"
#include "ui_fcacs.h"

FCACS::FCACS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FCACS)
{
    ui->setupUi(this);
}

FCACS::~FCACS()
{
    delete ui;
}
