#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QWidget>
#include <QDialog>
#include "displaylist.h"

#include "mainwindow.h"

namespace Ui {
class editPerson;
}

class editPerson : public QDialog
{
    Q_OBJECT

public:
    explicit editPerson(QWidget *parent = 0);
    ~editPerson();

private slots:
    void on_pBEdit_clicked();

    void on_pBCancel_clicked();

private:
    Ui::editPerson *ui;
};

#endif // EDITPERSON_H
