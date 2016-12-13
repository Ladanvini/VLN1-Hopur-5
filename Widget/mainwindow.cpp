#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QPixmap pix("/Users/BjarniKristinn/VLN1-Hopur-5/Widget/Unicorn.png") ;
    //ui->label_pix->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBDisplay_clicked()
{
    DisplayList dp(this);
    this->hide();//this hides the main menu window while we´re in a diffirent menu
    dp.exec();
    this->show();//this pops him back from hiding when we're done in the old one
}

void MainWindow::on_pBSearch_clicked()
{
    SearchMenu sm(this);
    this->hide();
    sm.exec();
    this->show();
}

void MainWindow::on_pBExit_clicked()
{
    this->close();
    qApp->exit();
}

void MainWindow::on_pBFunMenu_clicked()
{
    FunMenu fm(this);
    this->hide();
    fm.exec();
    this->show();
}
