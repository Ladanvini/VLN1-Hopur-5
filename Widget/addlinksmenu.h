#ifndef ADDLINKSMENU_H
#define ADDLINKSMENU_H

#include <QWidget>
#include <QDialog>
#include "mainwindow.h"
#include "displaylist.h"

namespace Ui {
class AddLinksMenu;
}

class AddLinksMenu : public QDialog {
    Q_OBJECT
public:
    explicit AddLinksMenu(QWidget *parent = 0);
    ~AddLinksMenu();
    vector<Links> currentlyDisplayedLinks;
    vector<Person> currentlyDisplayedPeople;
    vector<Comps> currentlyDisplayedComps;

private slots:
    void on_pLAdd_clicked();
    void on_pLBack_clicked();

    void on_table_person_clicked(const QModelIndex &index);

    void on_table_comps_clicked(const QModelIndex &index);

private:
    Ui::AddLinksMenu *ui;

    void displayPeople();
    void displayComps();


};

#endif // ADDLINKSMENU_H
