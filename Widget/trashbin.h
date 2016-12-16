#ifndef TRASHBIN_H
#define TRASHBIN_H

#include <QDialog>
#include "trashservice.h"
#include "mainwindow.h"

namespace Ui {
class TrashBin;
}

class TrashBin : public QDialog {
    Q_OBJECT
public:
    explicit TrashBin(QWidget *parent = 0);
    ~TrashBin();
    vector<Person> currentlyDisplayedPerson;
    vector<Comps> currentlyDisplayedComps;
    vector<Links> currentlyDisplayedLink;
private slots:
    void on_pBLRestore_clicked();
    void on_pBCRestore_clicked();
    void on_pBPRestore_clicked();
    void on_pBPTBack_clicked();
    void on_pBCTBack_clicked();
    void on_pBLTBack_clicked();
    void on_ListPersons_clicked(const QModelIndex &index);

    void on_ListComputers_clicked(const QModelIndex &index);

    void on_ListLinks_clicked(const QModelIndex &index);

private:
    Ui::TrashBin *ui;
    TrashService _ts;
    void displayPeople();
    void displayComps();
    void displayLinks();

};

#endif // TRASHBIN_H
