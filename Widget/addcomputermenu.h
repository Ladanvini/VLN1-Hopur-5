#ifndef ADDCOMPUTERMENU_H
#define ADDCOMPUTERMENU_H

#include <QWidget>
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddComputerMenu;
}

class AddComputerMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerMenu(QWidget *parent = 0);
    ~AddComputerMenu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddComputerMenu *ui;
};

#endif // ADDCOMPUTERMENU_H
