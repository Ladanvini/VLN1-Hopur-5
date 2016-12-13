#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include <QWidget>
#include <QDialog>

#include "mainwindow.h"


namespace Ui {
class DisplayList;
}

class DisplayList : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayList(QWidget *parent = 0);
    ~DisplayList();

private slots:
    void on_pBPBack_clicked();

    void on_pBLBack_clicked();

    void on_pBCBack_clicked();

private:
    Ui::DisplayList *ui;
};

#endif // DISPLAYLIST_H
