
//#include "chessboard.h"
//#include "ui_chessboard.h"
//#include "movementlabel.h"
//#include <QFile>
////#include <QTextStream>
////#include <QGraphicsItem>
////#include <QGraphicsRectItem>
////#include <QObject>
////#include <QGraphicsPixmapItem>






////int count=0,turn=1,exp[60],max=0;
////int size=56;



//chessboard::chessboard(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::chessboard)
//{
//    ui->setupUi(this);

//    connect(ui->bpawn1,SIGNAL(Mouse_Pos(QPoint&)), this, SLOT(Mouse_current_pos(QPoint&)));
//    connect(ui->bpawn1, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));
//    connect(ui->bpawn1, SIGNAL(Mouse_Left()), this, SLOT(Mouse_left()));

//}


//chessboard::~chessboard()
//{

//    delete ui;
//}


//void chessboard::on_goback_clicked()
//{
//    this->close();

//}
//void chessboard::Mouse_current_pos(QPoint &pos)
//{
//        ui->player1->setText("x: " + QString::number(pos.x()) + ", y: " + QString::number(pos.y()));

//        ui->player2->setText("Mouse Moving ");
//}

//void chessboard::Mouse_Pressed()
//{
//        ui->player2->setText("Mouse Pressed");
//}

//void chessboard::Mouse_left()
//{
//    ui->player2->setText("Mouse left");
//}


//void chessboard::display(char elem)
//{

//    this->pieceName=elem;
//    if(this->pieceColor && this->piece)
//     {

//        switch (elem)
//        {
//             case 'P': image.load(":/eachpiece/pawn_white.svg");
//                       scene = new QGraphicsScene(this);
//                       scene->addPixmap(image);
//                       break;
//             case 'R': image.load(":/eachpiece/rook_white.svg");
//                       scene = new QGraphicsScene(this);
//                       scene->addPixmap(image);
//                       break;
//             case 'H': image.load(":/eachpiece/knight_white.svg");
//                       scene = new QGraphicsScene(this);
//                       scene->addPixmap(image);
//                       break;
//             case 'K': image.load(":/eachpiece/king_white.svg");
//                       scene = new QGraphicsScene(this);
//                       scene->addPixmap(image);
//                       break;
//             case 'Q': image.load(":/eachpiece/queen_white.svg");
//                       scene = new QGraphicsScene(this);
//                       scene->addPixmap(image);
//                       break;
//             case 'B': image.load(":/eachpiece/bishop_white.svg");
//                       scene = new QGraphicsScene(this);
//                       scene->addPixmap(image);
//                       break;
//        }
//    }

//    else if(this->piece)
//    {
//        switch(elem)
//        {
//        case 'P': image.load(":/eachpiece/pawn_black.svg");
//                  scene = new QGraphicsScene(this);
//                  scene->addPixmap(image);
//                  break;
//        case 'R': image.load(":/eachpiece/rook_black.svg");
//                  scene = new QGraphicsScene(this);
//                  scene->addPixmap(image);
//                  break;
//        case 'H': image.load(":/eachpiece/knight_black.svg");
//                  scene = new QGraphicsScene(this);
//                  scene->addPixmap(image);
//                  break;
//        case 'K': image.load(":/eachpiece/king_black.svg");
//                  scene = new QGraphicsScene(this);
//                  scene->addPixmap(image);
//                  break;
//        case 'Q': image.load(":/eachpiece/queen_black.svg");
//                  scene = new QGraphicsScene(this);
//                  scene->addPixmap(image);
//                  break;
//        case 'B': image.load(":/eachpiece/bishop_black.svg");
//                  scene = new QGraphicsScene(this);
//                  scene->addPixmap(image);
//                  break;
//        }
//    }
//    else
//        scene = new QGraphicsScene(this);
//        scene->clear();
//}


//void chessboard::intialiseBoard()
//{
//    int x,y, k=0,hor, ver;
//    ver=125;
//    for (y = 0; y < 8; y++) {
//        hor=350;
//        for (x = 0; x < 8; x++) {
//            if (((x + y) % 2) == 0) {;
//                board[y][x] = piece = 0;
//                board[y][x] = row = y;
//                board[y][x] = col = x;
//                board[y][x] = tileNum = k++;
////                ui->wrook1->setGeometry(hor,ver,64,64);
////                ui->wrook1->show();

//            }
//            hor+=64;
//        }
//        ver+=64;
//    }
//    //white pawns
//    for(x=0;x<8;x++)
//    {
//        board[1][x]=piece=1;
//        board[1][x]=pieceColor=0;
//        QPixmap pix(":/eachpiece/rook_white.svg");
//        ui->wrook1->setPixmap(pix);
//    }

//    //black pawns
//    for(x=0;x<8;x++)
//    {
//        board[6][x]=piece=1;
//        board[6][x]=pieceColor=1;
//        QPixmap pix(":/eachpiece/rook_black.svg");
//        ui->brook1->setPixmap(pix);
//    }

//    //white and black remaining elements
//    for(x=0;x<8;x++)
//    {
//        board[0][x]=piece=1;
//        board[0][x]=pieceColor=0;
//        board[7][x]=piece=1;
//        board[7][x]=pieceColor=1;
//        QPixmap pix(":/eachpiece/pawn_white.svg");
//        ui->wprawn1->setPixmap(pix);
//    }

//    {


//    QPixmap pix(":/eachpiece/rook_black.svg");
//    ui->brook1->setPixmap(pix);


//    }



//}

////void chessboard::displayboard()
////{
////    for (int y = 0; y < 8; y++) {
////        for (int x = 0; x < 8; x++) {

////        }

////    }
////}



////void chessboard::loadPosition()
////{
////    int k=0;
////        for(int i=0;i<8;i++)
////         for(int j=0;j<8;j++)
////         {
////           int n = board[y][x];
////           if (!n) continue;
////           int x = abs(n)-1;
////           int y = n>0?1:0;
////           display->setGeometry->(size*x,size*y,size,size);
////           display->size(size*j,size*i);
////           k++;
////         }
////}

////int n = board[y][x];
////if(!n) continue;
////int x = abs (n) - 1;
////int y = n>0?1:0;
////scene = new QGraphicsScene(this);
////ui->graphicsView->setScene(scene);
////scene->setaddEllipse(size*x,size*y,64,64);
////k++;



//void chessboard::on_pushButton_clicked()
//{
//    intialiseBoard();
//}
