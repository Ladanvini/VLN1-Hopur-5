#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include <QWidget>
#include <QDialog>
namespace Ui {
class SearchMenu;
}

class SearchMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SearchMenu(QWidget *parent = 0);
    ~SearchMenu();

private:
    Ui::SearchMenu *ui;
};

#endif // SEARCHMENU_H
