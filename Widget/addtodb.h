#ifndef ADDTODB_H
#define ADDTODB_H

#include <QWidget>

namespace Ui {
class AddToDB;
}

class AddToDB : public QWidget
{
    Q_OBJECT

public:
    explicit AddToDB(QWidget *parent = 0);
    ~AddToDB();

private:
    Ui::AddToDB *ui;
};

#endif // ADDTODB_H
