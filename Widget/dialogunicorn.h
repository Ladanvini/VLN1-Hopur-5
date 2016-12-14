#ifndef DIALOGUNICORN_H
#define DIALOGUNICORN_H

#include <QDialog>

namespace Ui {
class DialogUnicorn;
}

class DialogUnicorn : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUnicorn(QWidget *parent = 0);
    ~DialogUnicorn();

private:
    Ui::DialogUnicorn *ui;
};

#endif // DIALOGUNICORN_H
