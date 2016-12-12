#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QPixmap pix("/Users/BjarniKristinn/VLN1-Hopur-5/Widget/Unicorn.png") ;
    ui->label_pix->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBDisplay_clicked()
{
    DisplayList* dp = new DisplayList(this);
    this->close();
    //dp->show();
    dp->showNormal();

}
