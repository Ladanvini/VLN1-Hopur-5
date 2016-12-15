#ifndef TRASHBIN_H
#define TRASHBIN_H

#include <QDialog>
#include "trashservice.h"

namespace Ui {
class TrashBin;
}

class TrashBin : public QDialog
{
    Q_OBJECT

public:
    explicit TrashBin(QWidget *parent = 0);
    ~TrashBin();
    vector<Person> currentlyDisplayedPerson;
    vector<Comps> currentlyDisplayedComps;
    vector<Links> currentlyDisplayedLink;

private:
    Ui::TrashBin *ui;
    TrashService _ts;
    void displayPeople();
    void displayComps();
    void displayLinks();
};

#endif // TRASHBIN_H
