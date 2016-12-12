#ifndef ADDCOMPUTERMENU_H
#define ADDCOMPUTERMENU_H

#include <QWidget>

namespace Ui {
class AddComputerMenu;
}

class AddComputerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AddComputerMenu(QWidget *parent = 0);
    ~AddComputerMenu();

private:
    Ui::AddComputerMenu *ui;
};

#endif // ADDCOMPUTERMENU_H
