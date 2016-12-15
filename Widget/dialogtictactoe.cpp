#include "dialogtictactoe.h"
#include "ui_dialogtictactoe.h"

DialogTicTacToe::DialogTicTacToe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTicTacToe)
{
    ui->setupUi(this);



   this->setWindowTitle("TicTacToe-");


   scene = new QGraphicsScene(this);

   ui->graphicsView->setScene(scene);

   scene->setBackgroundBrush(Qt::white);



   ui->graphicsView->setRenderHint(QPainter::Antialiasing);


   QLineF topLine(scene->sceneRect().topLeft(),
                  scene->sceneRect().topRight());
   QLineF leftLine(scene->sceneRect().topLeft(),
                   scene->sceneRect().bottomLeft());
   QLineF rightLine(scene->sceneRect().topRight(),
                    scene->sceneRect().bottomRight());
   QLineF bottomLine(scene->sceneRect().bottomLeft(),
                     scene->sceneRect().bottomRight());

   QPen myPen = QPen(Qt::black);




   scene->addLine(topLine, myPen);
   scene->addLine(leftLine, myPen);
   scene->addLine(rightLine, myPen);
   scene->addLine(bottomLine, myPen);


   //Create Rect Item

   QGraphicsRectItem * rect = new QGraphicsRectItem(50,100,100,100);
      QGraphicsRectItem * rect1 = new QGraphicsRectItem(150,100,100,100);
      QGraphicsRectItem * rect2 = new QGraphicsRectItem(250,100,100,100);
      QGraphicsRectItem * rect3 = new QGraphicsRectItem(50,200,100,100);
      QGraphicsRectItem * rect4 = new QGraphicsRectItem(150,200,100,100);
      QGraphicsRectItem * rect5 = new QGraphicsRectItem(250,200,100,100);
      QGraphicsRectItem * rect6 = new QGraphicsRectItem(50,300,100,100);
      QGraphicsRectItem * rect7 = new QGraphicsRectItem(150,300,100,100);
      QGraphicsRectItem * rect8 = new QGraphicsRectItem(250,300,100,100);


      // Add item to the scene.

      scene->addItem(rect);
      scene->addItem(rect1);
      scene->addItem(rect2);
      scene->addItem(rect3);
      scene->addItem(rect4);
      scene->addItem(rect5);
      scene->addItem(rect6);
      scene->addItem(rect7);
      scene->addItem(rect8);

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


