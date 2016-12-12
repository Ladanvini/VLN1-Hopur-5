#include "fcacs.h"
#include "fcacs.ui"


FCACS::FCACS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FCACS)
{
    ui->setupUi(this);
    ui->Display("Display");

}

FCACS::~FCACS()
{
    delete ui;
}
