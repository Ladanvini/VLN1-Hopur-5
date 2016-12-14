#ifndef DIALOGMOONWALK_H
#define DIALOGMOONWALK_H

#include <QDialog>

namespace Ui {
class DialogMoonWalk;
}

class DialogMoonWalk : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMoonWalk(QWidget *parent = 0);
    ~DialogMoonWalk();

private:
    Ui::DialogMoonWalk *ui;
};

#endif // DIALOGMOONWALK_H
