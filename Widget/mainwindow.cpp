#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";
    _ps = appservice(_dbpath);
    _cs = CompService(_dbpath);
    _ls = LinkService(_dbpath);

    QPixmap pix("/Users/BjarniKristinn/VLN1-Hopur-5/Widget/Unicorn.png") ;
    //ui->label_pix->setPixmap(pix);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pBDisplay_clicked() {
    DisplayList dp(this);
    dp.exec();
}

void MainWindow::on_pBExit_clicked() {
    this->close();
    qApp->exit();
}

void MainWindow::on_pBFunMenu_clicked() {
    FunMenu fm;
    fm.exec();
}

void MainWindow::on_pBTrash_clicked() {
    TrashBin tb(this);
    tb.exec();
}
