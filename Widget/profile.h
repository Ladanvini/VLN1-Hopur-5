#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>

#include "displaylist.h"
#include "mainwindow.h"

namespace Ui {
class Profile;
}

class Profile : public QDialog {
    Q_OBJECT
public:
    explicit Profile(QWidget *parent = 0);
    ~Profile();
    void showPersonWithID(int id);
private slots:
    void on_pProBack_clicked();
private:
    Ui::Profile *ui;

};

#endif // PROFILE_H
