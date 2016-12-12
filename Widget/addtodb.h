#ifndef ADDTODB_H
#define ADDTODB_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class AddToDB;
}

class AddToDB : public QDialog
{
    Q_OBJECT

public:
    explicit AddToDB(QWidget *parent = 0);
    ~AddToDB();

private:
    Ui::AddToDB *ui;
};

#endif // ADDTODB_H
