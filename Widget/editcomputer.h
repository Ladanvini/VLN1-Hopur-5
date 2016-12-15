#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class editComputer;
}

class editComputer : public QDialog {
    Q_OBJECT
public:
    explicit editComputer(QWidget *parent = 0);
    ~editComputer();
private slots:
    void on_pBBack_clicked();

    void on_pBAdd_clicked();

private:
    Ui::editComputer *ui;

};

#endif // EDITCOMPUTER_H
