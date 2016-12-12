#ifndef FUNMENU_H
#define FUNMENU_H

#include <QDialog>

namespace Ui {
class FunMenu;
}

class FunMenu : public QDialog
{
    Q_OBJECT

public:
    explicit FunMenu(QWidget *parent = 0);
    ~FunMenu();

private:
    Ui::FunMenu *ui;
};

#endif // FUNMENU_H
