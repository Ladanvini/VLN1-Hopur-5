#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include <QWidget>
#include <QDialog>
#include "mainwindow.h"
#include "addcomputermenu.h"
#include "personcreatemenu.h"
#include "addlinksmenu.h"

namespace Ui {
class DisplayList;
}

class DisplayList : public QDialog {
    Q_OBJECT
public:
    explicit DisplayList(QWidget *parent = 0);
    ~DisplayList();
    void displayPeople();
    void displayComps();
    void displayLinks();
    void displayPeople(vector<Person> peeps);
    void displayComps(vector<Comps> computs);
    void displayLinks(vector<Links> links);

    vector<Person> currentlyDisplayedPerson;
    vector<Comps> currentlyDisplayedComps;
    vector<Links> currentlyDisplayedLink;

private slots:
    void on_pBPBack_clicked();
    void on_pBLBack_clicked();
    void on_pBCBack_clicked();
    void on_pBCAdd_clicked();
    void on_tableWidget_activated(const QModelIndex &index);
    void on_ListComputers_clicked(const QModelIndex &index);
    void on_pBLAdd_clicked();
    void on_pBPAdd_clicked();
    void on_ListLinks_clicked(const QModelIndex &index);
    void on_ListPersons_clicked(const QModelIndex &index);
    void on_pBPDelete_clicked();
    void on_pBCDelete_clicked();
    void on_pBLDelete_clicked();
    void on_pBPEdit_clicked();
    void on_pBCEdit_clicked();
    void on_input_SearchComp_clicked();

    void on_input_SearchPers_clicked();


    void on_cB_SearchForPers_currentTextChanged(const QString &arg1);



    void on_input_SearchLink_clicked();

    void on_ListPersons_doubleClicked(const QModelIndex &index);

private:
    Ui::DisplayList *ui;


};

#endif // DISPLAYLIST_H
