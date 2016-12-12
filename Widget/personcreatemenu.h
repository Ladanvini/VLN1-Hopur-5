#ifndef PERSONCREATEMENU_H
#define PERSONCREATEMENU_H

#include <QWidget>

namespace Ui {
class PersonCreateMenu;
}

class PersonCreateMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PersonCreateMenu(QWidget *parent = 0);
    ~PersonCreateMenu();

private:
    Ui::PersonCreateMenu *ui;
};

#endif // PERSONCREATEMENU_H
