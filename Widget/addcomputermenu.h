#ifndef ADDCOMPUTERMENU_H
#define ADDCOMPUTERMENU_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class AddComputerMenu;
}

class AddComputerMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerMenu(QWidget *parent = 0);
    ~AddComputerMenu();

private:
    Ui::AddComputerMenu *ui;
};

#endif // ADDCOMPUTERMENU_H
