#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ctime>

#include "appservice.h"
#include "compservice.h"
#include "linkservice.h"

#include "displaylist.h"
#include "addtodb.h"
#include "searchmenu.h"
#include "funmenu.h"

static QString _dbpath = "/Users/BjarniKristinn/VLN1-Hopur-5/create.sqlite";
static appservice _ps = appservice(_dbpath);
static CompService _cs = CompService(_dbpath);
static LinkService _ls = LinkService(_dbpath);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pBDisplay_clicked();

    void on_pBSearch_clicked();

    //void on_pBDelete_clicked();

    void on_pBExit_clicked();

    void on_pBFunMenu_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
