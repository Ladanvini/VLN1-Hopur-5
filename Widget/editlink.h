#ifndef EDITLINK_H
#define EDITLINK_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class EditLink;
}

class EditLink : public QDialog {
    Q_OBJECT
public:
    explicit EditLink(QWidget *parent = 0);
    ~EditLink();
private slots:
    void on_pBEdit_clicked();
    void on_pBBack_clicked();
private:
    Ui::EditLink *ui;

};

#endif // EDITLINK_H
