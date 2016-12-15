#include "dialogtictactoe.h"
#include "ui_dialogtictactoe.h"
#include <QMessageBox>

DialogTicTacToe::DialogTicTacToe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTicTacToe)
{
    QPainter *painter = new QPainter(this);

    painter->setPen(Qt::green);
    ui->setupUi(this);



   this->setWindowTitle("TicTacToe-");


   scene = new QGraphicsScene(this);

   ui->graphicsView->setScene(scene);

   scene->setBackgroundBrush(Qt::white);



   ui->graphicsView->setRenderHint(QPainter::Antialiasing);


   //Create Rect Item

      QGraphicsRectItem * rects = new QGraphicsRectItem(50,100,100,100);
      QGraphicsRectItem * rects1 = new QGraphicsRectItem(150,100,100,100);
      QGraphicsRectItem * rects2 = new QGraphicsRectItem(250,100,100,100);
      QGraphicsRectItem * rects3 = new QGraphicsRectItem(50,200,100,100);
      QGraphicsRectItem * rects4 = new QGraphicsRectItem(150,200,100,100);
      QGraphicsRectItem * rects5 = new QGraphicsRectItem(250,200,100,100);
      QGraphicsRectItem * rects6 = new QGraphicsRectItem(50,300,100,100);
      QGraphicsRectItem * rects7 = new QGraphicsRectItem(150,300,100,100);
      QGraphicsRectItem * rects8 = new QGraphicsRectItem(250,300,100,100);


      // Add item to the scene.

          scene->addItem(rects);
          scene->addItem(rects1);
          scene->addItem(rects2);
          scene->addItem(rects3);
          scene->addItem(rects4);
          scene->addItem(rects5);
          scene->addItem(rects6);
          scene->addItem(rects7);
          scene->addItem(rects8);



}

DialogTicTacToe::~DialogTicTacToe()
{
    delete ui;
}

void DialogTicTacToe::on_pBExit_clicked(){

    DialogTicTacToe t;
    t.close();
    this ->close();


}
//void DialogTicTacToe::TicTacToeSource(){








//TicTacToe InitializeBoard();


//TicTacToe printBoard();


//TicTacToe::InsertIntoBoard();

// I am trying to figgure this out.
/*TicTacToe::CheckIfWinner();
if(false){

    QMessageBox::StandardButton reply;
    replay = QMessageBox::question(this, "The Game is over. Do you want to play new game",
            QMessageBox::Yes|QMessageBox::No);


*/





//}
*/


