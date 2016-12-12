#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "appservice.h"
#include "compservice.h"
#include "linkservice.h"

static QString _dbpath = QCoreApplication::applicationDirPath() + "/create.sqlite";
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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
