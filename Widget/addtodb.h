#ifndef ADDTODB_H
#define ADDTODB_H

#include <QWidget>
#include <QDialog>

#include "mainwindow.h"


namespace Ui {
class AddToDB;
}

class AddToDB : public QDialog
{
    Q_OBJECT

public:
    explicit AddToDB(QWidget *parent = 0);
    ~AddToDB();

private slots:
    void on_pBABack_clicked();

private:
    Ui::AddToDB *ui;
};

#endif // ADDTODB_H
