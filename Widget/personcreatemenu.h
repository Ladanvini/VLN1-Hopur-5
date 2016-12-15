#ifndef PERSONCREATEMENU_H
#define PERSONCREATEMENU_H

#include <QWidget>
#include <QDialog>
#include <locale>
#include "displaylist.h"

namespace Ui {
class PersonCreateMenu;
}

class PersonCreateMenu : public QDialog {
    Q_OBJECT
public:
    explicit PersonCreateMenu(QWidget *parent = 0);
    ~PersonCreateMenu();
    bool isNumb(string inputname);
private slots:
    void on_pBAddPerson_clicked();
    void on_pBBack_clicked();
private:
    Ui::PersonCreateMenu *ui;

};

#endif // PERSONCREATEMENU_H
