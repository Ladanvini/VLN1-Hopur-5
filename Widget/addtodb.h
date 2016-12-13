#ifndef ADDTODB_H
#define ADDTODB_H

#include <QWidget>
#include <QDialog>

#include "mainwindow.h"
#include "personcreatemenu.h"
#include "addcomputermenu.h"


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

    void on_pBAAddP_clicked();

    void on_pBAAddC_clicked();

private:
    Ui::AddToDB *ui;
};

#endif // ADDTODB_H
