#ifndef DIALOGTICTACTOE_H
#define DIALOGTICTACTOE_H

#include <QDialog>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mainwindow.h"
#include "funmenu.h"
#include "tictactoe.h"
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

    void TicTacToeSource();


protected:


private:
    Ui::DialogTicTacToe *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem rects[9];
    QLine lines[9];



private slots:

    void on_pBExit_clicked();


};
#endif // DIALOGTICTACTOE_H
