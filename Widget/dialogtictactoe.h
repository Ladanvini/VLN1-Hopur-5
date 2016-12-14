#ifndef DIALOGTICTACTOE_H
#define DIALOGTICTACTOE_H

#include <QDialog>

namespace Ui {
class DialogTicTacToe;
}

class DialogTicTacToe : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTicTacToe(QWidget *parent = 0);
    ~DialogTicTacToe();

private:
    Ui::DialogTicTacToe *ui;
};

#endif // DIALOGTICTACTOE_H
