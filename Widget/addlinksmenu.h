#ifndef ADDLINKSMENU_H
#define ADDLINKSMENU_H

#include <QWidget>
#include <QDialog>
#include "mainwindow.h"
#include "displaylist.h"

namespace Ui {
class AddLinksMenu;
}

class AddLinksMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AddLinksMenu(QWidget *parent = 0);
    ~AddLinksMenu();

private slots:
    void on_pLAdd_clicked();

    void on_pLBack_clicked();

private:
    Ui::AddLinksMenu *ui;
};

#endif // ADDLINKSMENU_H
