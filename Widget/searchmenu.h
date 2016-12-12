#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include <QWidget>
#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class SearchMenu;
}

class SearchMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SearchMenu(QWidget *parent = 0);
    ~SearchMenu();

private slots:
    void on_pbGoBackPer_clicked();

    void on_pBGoBackCom_clicked();

private:
    Ui::SearchMenu *ui;
};

#endif // SEARCHMENU_H
