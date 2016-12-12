#ifndef FUNMENU_H
#define FUNMENU_H

#include <QDialog>

#include "mainwindow.h"


namespace Ui {
class FunMenu;
}

class FunMenu : public QDialog
{
    Q_OBJECT

public:
    explicit FunMenu(QWidget *parent = 0);
    ~FunMenu();

private slots:
    void on_pBBack_clicked();

private:
    Ui::FunMenu *ui;
};

#endif // FUNMENU_H
