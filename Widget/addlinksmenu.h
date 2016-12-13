#ifndef ADDLINKSMENU_H
#define ADDLINKSMENU_H

#include <QDialog>

namespace Ui {
class AddLinksMenu;
}

class AddLinksMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AddLinksMenu(QWidget *parent = 0);
    ~AddLinksMenu();

private:
    Ui::AddLinksMenu *ui;
};

#endif // ADDLINKSMENU_H
