#include "dialogtictactoe.h"
#include "ui_dialogtictactoe.h"

DialogTicTacToe::DialogTicTacToe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTicTacToe)
{
    ui->setupUi(this);
}

DialogTicTacToe::~DialogTicTacToe()
{
    delete ui;
}
