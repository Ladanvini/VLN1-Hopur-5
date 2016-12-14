#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";
     _ps = appservice(_dbpath);
    _cs = CompService(_dbpath);
    _ls = LinkService(_dbpath);

    //cout << _dbpath.toStdString() << endl;
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
    //this->hide();//this hides the main menu window while we´re in a diffirent menu
    dp.exec();
    //this->show();//this pops him back from hiding when we're done in the old one
}

void MainWindow::on_pBSearch_clicked()
{
    SearchMenu sm;
    sm.exec();
}

void MainWindow::on_pBExit_clicked()
{
    this->close();
    qApp->exit();
}

void MainWindow::on_pBFunMenu_clicked()
{
    FunMenu fm;
    //this->hide();
    fm.exec();
    //this->show();
}
