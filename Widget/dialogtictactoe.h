#ifndef DIALOGTICTACTOE_H
#define DIALOGTICTACTOE_H

#include <QDialog>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mainwindow.h"
#include "funmenu.h"
#include <QPainter>

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
    QGraphicsScene *scene;

private slots:

    void on_pBExit_clicked();

};
#endif // DIALOGTICTACTOE_H
