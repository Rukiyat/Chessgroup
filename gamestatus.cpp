#include "gamestatus.h"
#include "ui_gamestatus.h"
#include "walls.h"
#include "multiplayerlogin.h"
#include "loginuser.h"
#include <QPushButton>
#include "validatemoves.h"
#include <QtGui>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <QtCore>
#include <QTableWidget>
#include <unistd.h>
#include <QThread>
#include "savemoves.h"
#include <QMessageBox>
#include <QObject>
#include "buttonsheader.h"
#include "screenwindow.h"

validatemoves *valid = new validatemoves;
extern QString player1username, player2username;
void validate(walls *temp, int c,QWidget *baseWidget);
void disOrange();
static QString position,newposition,piecename,pieceColour,piecePresent,playersturn,saveposition;





int count=0, turn=1, expw[60], max=0;


int wR,wC,bR,bC;
walls *click1;
walls *temp;
walls *tile[8][8] = { { NULL } };

void walls::mousePressEvent(QMouseEvent *event)
{
    QWidget *baseWidget=nullptr;
    validate(this,++count,baseWidget);
}


gamestatus::gamestatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamestatus)
{
    ui->setupUi(this);
    ui->welcomemsg->setText("WELCOME TO CAPTURE THE ENEMY");

}

gamestatus::~gamestatus()
{
    delete ui;
}


class Border
{
public:
    Border();
    void outline(QWidget *baseWidget, int xPos, int yPos, int Pos)
    {
         QLabel *outLabel = new QLabel(baseWidget);

        if(!Pos)
            outLabel->setGeometry(xPos,yPos,552,20);        //Horizontal Borders

        else
            outLabel->setGeometry(xPos,yPos,20,512);        //Vertical Borders

        outLabel->setStyleSheet("QLabel { background-color :rgb(170, 170, 127); color : black; }");
    }

};


//performs what the undo function should do.
void Undo()
{

    savemoves connection;


    connection.connOpen();
    QSqlQuery* savequery= new QSqlQuery(connection.pdatabase);
    savequery->prepare("Delete from savemoves where PieceColour ='"+pieceColour+"',PieceName='"+piecename+"',PiecePresent='"+piecePresent+"',PiecePosition='"+saveposition+"',username='"+playersturn+"'");
    if (savequery->exec())
    {
        QMessageBox message;
        message.setText("DATA DELETED");
        message.exec();
        connection.connClose();
    }
    else
    {
        QMessageBox message;
        message.setText("UNABLE TO DELETE");
        message.exec();
    }



}

//performs what the go back function should do
void gogoback()
{
    gamestatus *gaming;
    gaming = new gamestatus;
    gaming->show();
}

void save()
{

}

void instructions()
{
    QMessageBox message;
    message.setText("WELCOME TO CAPTURE THE ENEMY! THE PIECES ARE Pawn=Soldier ROOK=BOMB  KING=WIZARD W=WIZARD BISHOP=PRIEST KNIGHT=HORSE");
    message.exec();
}

//draws the buttongoback" and then calls the goback function
void buttongoback(QWidget *baseWidget)
{
    QPushButton *go = new QPushButton(baseWidget);
    go->setGeometry(0,670,100,30);
    go->setText("<- EXIT GAME");
    go->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(164, 164, 164, 255), stop:1 rgba(255, 255, 255, 255));");
    QAbstractAnimation::connect(but.undo, SIGNAL(clicked()), baseWidget, SLOT(goback()));

}



// draws the buttonUndo" and then calls undo function
void buttonUndo(QWidget *baseWidget) //
{
    buttonsheader but;
    but.undo = new QPushButton("UNDO MOVE",baseWidget); // defining a variable for the pushbutton
    but.undo->setGeometry(0,170,100,30); // defines the size and the position of the button
    but.undo->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(164, 164, 164, 255), stop:1 rgba(255, 255, 255, 255));"); // stylesheet defines font
    QAbstractAnimation::connect(but.undo, SIGNAL(clicked()), baseWidget, SLOT(Undo()));

}



//draws the "save" button and calls the function save.
void savebutton(QWidget *baseWidget)
{
    QPushButton *save = new QPushButton(baseWidget);
    save->setGeometry(850,670,100,30);
    save->setText("SAVE GAME");
    save->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(164, 164, 164, 255), stop:1 rgba(255, 255, 255, 255));");

}

//draws the button "how to play" and calls the function instructions.
void HowtoPlayInfo(QWidget *baseWidget)
{
    QPushButton *infoguide = new QPushButton(baseWidget);
    infoguide->setGeometry(10,30,80,40);
    infoguide->setText("How To Play");
    infoguide->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(164, 164, 164, 255), stop:1 rgba(255, 255, 255, 255));");
    QAbstractAnimation::connect(but.undo, SIGNAL(clicked()), baseWidget, SLOT(instructions()));
}



//initilization of the board
void chessBoard(QWidget *baseWidget, walls *tile[8][8])
{
    int i,j,k=0,hor,ver;
    Border *border[4]={ NULL };


    //borderDisplay
    {
    border[0]->outline(baseWidget,330,105,0);
    border[1]->outline(baseWidget,330,637,0);
    border[2]->outline(baseWidget,330,125,1);
    border[2]->outline(baseWidget,862,125,1);
    }

    //Create 64 tiles (allocating memories to the objects of Tile class)
    ver=125;
    for(i=0;i<8;i++)
    {
        hor=350;
        for(j=0;j<8;j++)
        {
            //empty squares
            tile[i][j] = new walls(baseWidget);
            tile[i][j]->tileColor=(i+j)%2;
            tile[i][j]->piece=0;
            tile[i][j]->row=i;
            tile[i][j]->col=j;
            tile[i][j]->tileNum=k++;
            tile[i][j]->wallDisplay();
            tile[i][j]->setGeometry(hor,ver,64,64);
            hor+=64;


        }
        ver+=64;

    }


     //squares that contains a piece
    //white soldiers piece colour=0
    for(j=0;j<8;j++)
    {
        tile[1][j]->piece=1;
        tile[1][j]->pieceColor=0;
        tile[1][j]->display('S');
    }

    //black soldiers piece colour 1
    for(j=0;j<8;j++)
    {
        tile[6][j]->piece=1;
        tile[6][j]->pieceColor=1;
        tile[6][j]->display('S');
    }

    //white and black remaining elements
    for(j=0;j<8;j++)
    {
        tile[0][j]->piece=1;
        tile[0][j]->pieceColor=0;
        tile[7][j]->piece=1;
        tile[7][j]->pieceColor=1;
    }

    {
    tile[0][0]->display('B');
    tile[0][1]->display('H');
    tile[0][2]->display('P');
    tile[0][3]->display('W');
    tile[0][4]->display('Z');
    tile[0][5]->display('P');
    tile[0][6]->display('H');
    tile[0][7]->display('B');

    }


    {
    tile[7][0]->display('B');
    tile[7][1]->display('H');
    tile[7][2]->display('P');
    tile[7][3]->display('W');
    tile[7][4]->display('Z');
    tile[7][5]->display('P');
    tile[7][6]->display('H');
    tile[7][7]->display('B');

    }


    wR=7;
    wC=4;

    bR=0;
    bC=4;

}


//validates the clicks and temps on the wall.
void validate(walls *temp,int c,QWidget *baseWidget)
{

    int retValue,i,j;

    enum Columna
    {
        PieceColour,Position,PieceName,NewPosition
    };


    //for each time the user touches the wall;
    disOrange();

    if(c==1)
    {

        //each time it's users turn to move a piece.
        if(temp->piece && (temp->pieceColor==turn))
        {

            //moving a piece and the colour
            expw[max++]=temp->tileNum;

// gets the position of the current piece.

            if(temp->tileNum==0)
            {
                position="A8";
            }

            else if(temp->tileNum==1)
            {
                position="B8";
            }

            else if(temp->tileNum==2)
            {
                position="C8";
            }

            else if(temp->tileNum==3)
            {
                position="D8";
            }

            else if(temp->tileNum==4)
            {
                position="E8";
            }

            else if(temp->tileNum==5)
            {
                position="F8";
            }

            else if(temp->tileNum==6)
            {
                position="G8";
            }

            else if(temp->tileNum==7)
            {
                position="H8";
            }

            else if(temp->tileNum==8)
            {
                position="A7";
            }

            else if(temp->tileNum==9)
            {
                position="B7";
            }

            else if(temp->tileNum==10)
            {
                position="C7";
            }

            else if(temp->tileNum==11)
            {
                position="D7";
            }

            else if(temp->tileNum==12)
            {
                position="E7";
            }
            else if(temp->tileNum==13)
            {
                position="F7";
            }

            else if(temp->tileNum==14)
            {
                position="G7";
            }

            else if(temp->tileNum==15)
            {
                position="H7";
            }

            else if(temp->tileNum==16)
            {
                position="A6";
            }

            else if(temp->tileNum==17)
            {
                position="B6";
            }

            else if(temp->tileNum==18)
            {
                position="C6";
            }

            else if(temp->tileNum==19)
            {
                position="D6";
            }

            else if(temp->tileNum==20)
            {
                position="E6";
            }

            else if(temp->tileNum==21)
            {
                position="F6";
            }

            else if(temp->tileNum==22)
            {
                position="G6";
            }

            else if(temp->tileNum==23)
            {
                position="H6";
            }

            else if(temp->tileNum==24)
            {
                position="A5";
            }

            else if(temp->tileNum==25)
            {
                position="B5";
            }

            else if(temp->tileNum==26)
            {
                position="C5";
            }

            else if(temp->tileNum==27)
            {
                position="D5";
            }

            else if(temp->tileNum==28)
            {
                position="E5";
            }

            else if(temp->tileNum==29)
            {
                position="F5";
            }

            else if(temp->tileNum==30)
            {
                position="G5";
            }

            else if(temp->tileNum==31)
            {
                position="H5";
            }

            else if(temp->tileNum==32)
            {
                position="A4";
            }

            else if(temp->tileNum==33)
            {
                position="B4";
            }

            else if(temp->tileNum==34)
            {
                position="C4";
            }

            else if(temp->tileNum==35)
            {
                position="D4";
            }

            else if(temp->tileNum==36)
            {
                position="E4";
            }

            else if(temp->tileNum==37)
            {
                position="F4";
            }

            else if(temp->tileNum==38)
            {
                position="G4";
            }

            else if(temp->tileNum==39)
            {
                position="H4";
            }

            else if(temp->tileNum==40)
            {
                position="A3";
            }

            else if(temp->tileNum==41)
            {
                position="B3";
            }

            else if(temp->tileNum==42)
            {
                position="C3";
            }

            else if(temp->tileNum==43)
            {
                position="D3";
            }

            else if(temp->tileNum==44)
            {
                position="E3";
            }

            else if(temp->tileNum==45)
            {
                position="F3";
            }

            else if(temp->tileNum==46)
            {
                position="G3";
            }

            else if(temp->tileNum==47)
            {
                position="H3";
            }

            else if(temp->tileNum==48)
            {
                position="A2";
            }

            else if(temp->tileNum==49)
            {
                position="B2";
            }

            else if(temp->tileNum==50)
            {
                position="C2";
            }


            else if(temp->tileNum==51)
            {
                position="D2";
            }

            else if(temp->tileNum==52)
            {
                position="E2";
            }

            else if(temp->tileNum==53)
            {
                position="F2";
            }

            else if(temp->tileNum==54)
            {
                position="G2";
            }

            else if(temp->tileNum==55)
            {
                position="H2";
            }

            else if(temp->tileNum==56)
            {
                position="A1";
            }

            else if(temp->tileNum==57)
            {
                position="B1";
            }

            else if(temp->tileNum==58)
            {
                position="C1";
            }

            else if(temp->tileNum==59)
            {
                position="D1";
            }

            else if(temp->tileNum==60)
            {
                position="E1";
            }

            else if(temp->tileNum==61)
            {
                position="F1";
            }

            else if(temp->tileNum==62)
            {

                position="G1";
            }

            else if(temp->tileNum==63)
            {
                position="H1";
            }




            //check if the specific piece move is valid.
            retValue=valid->chooser(temp);

            //if the move is legal retValue=1.
            if(retValue)
            {
               click1= new walls();
               temp->setStyleSheet("QLabel {background-color: green;}");
               click1=temp;

            }
            //if move is illegal.
            else
             {
                temp->setStyleSheet("QLabel {background-color: red;}");
                count=0;
             }


    }
        else
        {

            //doesn't allow user to move their piece if it isn't their turn
            count=0;

        }
    }

    else
    {

        if(temp->tileNum==click1->tileNum)
        {

            click1->wallDisplay();

            max=0;
            count=0;


        }
        //The final destination of the piece.
        for(i=0;i<max;i++)
        {
            //checks if it's whites turn and the wall clicked on is equivalent to a valid move square.
            if(temp->tileNum==expw[i] && turn==1)
            {

                //moving the piece characteristics from previous position to new position
                click1->piece=0;
                temp->piece=1;
                temp->pieceColor=click1->pieceColor;
                temp->pieceName=click1->pieceName;



// gets the newposition of the piece;

                if(temp->tileNum==0)
                {
                    newposition="A8";
                }

                else if(temp->tileNum==1)
                {
                    newposition="B8";
                }

                else if(temp->tileNum==2)
                {
                    newposition="C8";
                }

                else if(temp->tileNum==3)
                {
                    newposition="D8";
                }

                else if(temp->tileNum==4)
                {
                    newposition="E8";
                }

                else if(temp->tileNum==5)
                {
                    newposition="F8";
                }

                else if(temp->tileNum==6)
                {
                    newposition="G8";
                }

                else if(temp->tileNum==7)
                {
                    newposition="H8";
                }

                else if(temp->tileNum==8)
                {
                    newposition="A7";
                }

                else if(temp->tileNum==9)
                {
                    newposition="B7";
                }

                else if(temp->tileNum==10)
                {
                    newposition="C7";
                }

                else if(temp->tileNum==11)
                {
                    newposition="D7";
                }

                else if(temp->tileNum==12)
                {
                    newposition="E7";
                }
                else if(temp->tileNum==13)
                {
                    newposition="F7";
                }

                else if(temp->tileNum==14)
                {
                    newposition="G7";
                }

                else if(temp->tileNum==15)
                {
                    newposition="H7";
                }

                else if(temp->tileNum==16)
                {
                    newposition="A6";
                }

                else if(temp->tileNum==17)
                {
                    newposition="B6";
                }

                else if(temp->tileNum==18)
                {
                    newposition="C6";
                }

                else if(temp->tileNum==19)
                {
                    newposition="D6";
                }

                else if(temp->tileNum==20)
                {
                    newposition="E6";
                }

                else if(temp->tileNum==21)
                {
                    newposition="F6";
                }

                else if(temp->tileNum==22)
                {
                    newposition="G6";
                }

                else if(temp->tileNum==23)
                {
                    newposition="H6";
                }

                else if(temp->tileNum==24)
                {
                    newposition="A5";
                }

                else if(temp->tileNum==25)
                {
                    newposition="B5";
                }

                else if(temp->tileNum==26)
                {
                    newposition="C5";
                }

                else if(temp->tileNum==27)
                {
                    newposition="D5";
                }

                else if(temp->tileNum==28)
                {
                    newposition="E5";
                }

                else if(temp->tileNum==29)
                {
                    newposition="F5";
                }

                else if(temp->tileNum==30)
                {
                    newposition="G5";
                }

                else if(temp->tileNum==31)
                {
                    newposition="H5";
                }

                else if(temp->tileNum==32)
                {
                    newposition="A4";
                }

                else if(temp->tileNum==33)
                {
                    newposition="B4";
                }

                else if(temp->tileNum==34)
                {
                    newposition="C4";
                }

                else if(temp->tileNum==35)
                {
                    newposition="D4";
                }

                else if(temp->tileNum==36)
                {
                    newposition="E4";
                }

                else if(temp->tileNum==37)
                {
                    newposition="F4";
                }

                else if(temp->tileNum==38)
                {
                    newposition="G4";
                }

                else if(temp->tileNum==39)
                {
                    newposition="H4";
                }

                else if(temp->tileNum==40)
                {
                    newposition="A3";
                }

                else if(temp->tileNum==41)
                {
                    newposition="B3";
                }

                else if(temp->tileNum==42)
                {
                    newposition="C3";
                }

                else if(temp->tileNum==43)
                {
                    newposition="D3";
                }

                else if(temp->tileNum==44)
                {
                    newposition="E3";
                }

                else if(temp->tileNum==45)
                {
                    newposition="F3";
                }

                else if(temp->tileNum==46)
                {
                    newposition="G3";
                }

                else if(temp->tileNum==47)
                {
                    newposition="H3";
                }

                else if(temp->tileNum==48)
                {
                    newposition="A2";
                }

                else if(temp->tileNum==49)
                {
                    newposition="B2";
                }

                else if(temp->tileNum==50)
                {
                    newposition="C2";
                }


                else if(temp->tileNum==51)
                {
                    newposition="D2";
                }

                else if(temp->tileNum==52)
                {
                    newposition="E2";
                }

                else if(temp->tileNum==53)
                {
                    newposition="F2";
                }

                else if(temp->tileNum==54)
                {
                    newposition="G2";
                }

                else if(temp->tileNum==55)
                {
                    newposition="H2";
                }

                else if(temp->tileNum==56)
                {
                    newposition="A1";
                }

                else if(temp->tileNum==57)
                {
                    newposition="B1";
                }

                else if(temp->tileNum==58)
                {
                    newposition="C1";
                }

                else if(temp->tileNum==59)
                {
                    newposition="D1";
                }

                else if(temp->tileNum==60)
                {
                    newposition="E1";
                }

                else if(temp->tileNum==61)
                {
                    newposition="F1";
                }

                else if(temp->tileNum==62)
                {

                    newposition="G1";
                }

                else if(temp->tileNum==63)
                {
                    newposition="H1";
                }




                //displaying the board of the new position
                click1->display(click1->pieceName);
                temp->display(click1->pieceName);

                //displays the tile colour of the walls.
                click1->wallDisplay();
                temp->wallDisplay();

                //checks if move is illegal
                retValue=valid->check(click1);

                 //if illegal turn the square red.
                if(retValue)
                {
                    tile[wR][wC]->setStyleSheet("QLabel {background-color: red;}");


                }


                disOrange();

                if (temp->pieceColor==1 && turn==1)
                {
                    pieceColour="W";
                    qDebug() << pieceColour;
                    playersturn=player1username;

                }
                if (temp->pieceColor==0 && turn==0)
                {
                    pieceColour="B";
                    qDebug() << pieceColour;
                    playersturn=player2username;
                }


                piecePresent="1";

                piecename=temp->pieceName;

                max=0;

                //black's turn
                turn=(turn+1)%2;

                count=0;


            }

            //checks if it's blacks  turn and the wall clicked on is equivalent to a valid move square.
            else if(temp->tileNum==expw[i] && turn==0)
            {

                count=1;


                //moving the piece characteristics from previous position to new position
                click1->piece=0;
                temp->piece=1;
                temp->pieceColor=click1->pieceColor;
                temp->pieceName=click1->pieceName;


// gets the newposition of the piece
                if(temp->tileNum==0)
                {
                    newposition="A8";
                }

                else if(temp->tileNum==1)
                {
                    newposition="B8";
                }

                else if(temp->tileNum==2)
                {
                    newposition="C8";
                }

                else if(temp->tileNum==3)
                {
                    newposition="D8";
                }

                else if(temp->tileNum==4)
                {
                    newposition="E8";
                }

                else if(temp->tileNum==5)
                {
                    newposition="F8";
                }

                else if(temp->tileNum==6)
                {
                    newposition="G8";
                }

                else if(temp->tileNum==7)
                {
                    newposition="H8";
                }

                else if(temp->tileNum==8)
                {
                    newposition="A7";
                }

                else if(temp->tileNum==9)
                {
                    newposition="B7";
                }

                else if(temp->tileNum==10)
                {
                    newposition="C7";
                }

                else if(temp->tileNum==11)
                {
                    newposition="D7";
                }

                else if(temp->tileNum==12)
                {
                    newposition="E7";
                }
                else if(temp->tileNum==13)
                {
                    newposition="F7";
                }

                else if(temp->tileNum==14)
                {
                    newposition="G7";
                }

                else if(temp->tileNum==15)
                {
                    newposition="H7";
                }

                else if(temp->tileNum==16)
                {
                    newposition="A6";
                }

                else if(temp->tileNum==17)
                {
                    newposition="B6";
                }

                else if(temp->tileNum==18)
                {
                    newposition="C6";
                }

                else if(temp->tileNum==19)
                {
                    newposition="D6";
                }

                else if(temp->tileNum==20)
                {
                    newposition="E6";
                }

                else if(temp->tileNum==21)
                {
                    newposition="F6";
                }

                else if(temp->tileNum==22)
                {
                    newposition="G6";
                }

                else if(temp->tileNum==23)
                {
                    newposition="H6";
                }

                else if(temp->tileNum==24)
                {
                    newposition="A5";
                }

                else if(temp->tileNum==25)
                {
                    newposition="B5";
                }

                else if(temp->tileNum==26)
                {
                    newposition="C5";
                }

                else if(temp->tileNum==27)
                {
                    newposition="D5";
                }

                else if(temp->tileNum==28)
                {
                    newposition="E5";
                }

                else if(temp->tileNum==29)
                {
                    newposition="F5";
                }

                else if(temp->tileNum==30)
                {
                    newposition="G5";
                }

                else if(temp->tileNum==31)
                {
                    newposition="H5";
                }

                else if(temp->tileNum==32)
                {
                    newposition="A4";
                }

                else if(temp->tileNum==33)
                {
                    newposition="B4";
                }

                else if(temp->tileNum==34)
                {
                    newposition="C4";
                }

                else if(temp->tileNum==35)
                {
                    newposition="D4";
                }

                else if(temp->tileNum==36)
                {
                    newposition="E4";
                }

                else if(temp->tileNum==37)
                {
                    newposition="F4";
                }

                else if(temp->tileNum==38)
                {
                    newposition="G4";
                }

                else if(temp->tileNum==39)
                {
                    newposition="H4";
                }

                else if(temp->tileNum==40)
                {
                    newposition="A3";
                }

                else if(temp->tileNum==41)
                {
                    newposition="B3";
                }

                else if(temp->tileNum==42)
                {
                    newposition="C3";
                }

                else if(temp->tileNum==43)
                {
                    newposition="D3";
                }

                else if(temp->tileNum==44)
                {
                    newposition="E3";
                }

                else if(temp->tileNum==45)
                {
                    newposition="F3";
                }

                else if(temp->tileNum==46)
                {
                    newposition="G3";
                }

                else if(temp->tileNum==47)
                {
                    newposition="H3";
                }

                else if(temp->tileNum==48)
                {
                    newposition="A2";
                }

                else if(temp->tileNum==49)
                {
                    newposition="B2";
                }

                else if(temp->tileNum==50)
                {
                    newposition="C2";
                }


                else if(temp->tileNum==51)
                {
                    newposition="D2";
                }

                else if(temp->tileNum==52)
                {
                    newposition="E2";
                }

                else if(temp->tileNum==53)
                {
                    newposition="F2";
                }

                else if(temp->tileNum==54)
                {
                    newposition="G2";
                }

                else if(temp->tileNum==55)
                {
                    newposition="H2";
                }

                else if(temp->tileNum==56)
                {
                    newposition="A1";
                }

                else if(temp->tileNum==57)
                {
                    newposition="B1";
                }

                else if(temp->tileNum==58)
                {
                    newposition="C1";
                }

                else if(temp->tileNum==59)
                {
                    newposition="D1";
                }

                else if(temp->tileNum==60)
                {
                    newposition="E1";
                }

                else if(temp->tileNum==61)
                {
                    newposition="F1";
                }

                else if(temp->tileNum==62)
                {

                    newposition="G1";
                }

                else if(temp->tileNum==63)
                {
                    newposition="H1";
                }


                //displaying the board of the new position
                click1->display(click1->pieceName);
                temp->display(click1->pieceName);

                //displays the colour of each tile
                click1->wallDisplay();
                temp->wallDisplay();
                //checks if move is illegal
                retValue=valid->check(click1);
                 //if illegal turn the square red.
                if(retValue)
                {
                    tile[wR][wC]->setStyleSheet("QLabel {background-color: red;}");
                }


                disOrange();


                if (temp->pieceColor==1 && turn==1)
                {
                    pieceColour="W";
                    qDebug() << pieceColour;
                    playersturn=player1username;


                }
                if (temp->pieceColor==0 && turn==0)
                {
                    pieceColour="B";
                    qDebug() << pieceColour;
                    playersturn=player2username;
                }

                piecename=temp->pieceName;
                piecePresent="1";

                max=0;

                turn=1;

              //whites turn
                count=0;

            }
            //drawing the table and assigning its columns header list to each column.
            int rowcount=0;
            QTableView *tableview= new QTableView(baseWidget);
            QStandardItemModel *model = new QStandardItemModel(rowcount, 4, baseWidget); //increment Rows and 4 Columns
            model->setHorizontalHeaderItem(0, new QStandardItem(QString("P.Colour")));
            model->setHorizontalHeaderItem(1, new QStandardItem(QString("OldMove")));
            model->setHorizontalHeaderItem(2, new QStandardItem(QString("P.Name")));
            model->setHorizontalHeaderItem(3, new QStandardItem(QString("NewMove")));
            rowcount=model->rowCount(QModelIndex());
            //asssign it's values to each row.
            model->insertRow(rowcount);
            tableview->setModel(model);
            tableview->setGeometry(950,170,400,520);

            model->setItem(rowcount,PieceColour, new QStandardItem(pieceColour));
            model->setItem(rowcount,Position, new QStandardItem(position));
            model->setItem(rowcount,PieceName, new QStandardItem(piecename));
            model->setItem(rowcount,NewPosition, new QStandardItem(newposition));
            rowcount++;
            tableview->show();

        }
        sleep(double(0.4));

    }





    //connects the to the savemoves database connectiion
    savemoves connection;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            //saving just the piece characteristics that is present on the board.
            if (tile[i][j]->piece==1)
            {
                qDebug()<< tile[i][j]->pieceColor;
                qDebug()<< tile[i][j]->piece;
                qDebug()<< tile[i][j]->pieceName;
                qDebug()<< tile[i][j]->tileNum;


                //converting the white piecolour from integer=1 to string'W' to store in the database.
                if (tile[i][j]->pieceColor==1)
                {
                    pieceColour="W";
                    //if white asssign player1username to playersturn
                    playersturn=player1username;

                }
                else if (tile[i][j]->pieceColor==0)
                {
                    pieceColour="B";
                    //if white asssign player2username to playersturn
                    playersturn=player2username;
                }

                //converts the string tile number from integer into a string to store in the database.
                saveposition= QString::number(tile[i][j]->tileNum);
                piecePresent="1";
                piecename=tile[i][j]->pieceName;




                //opening up the databse to save the data
                connection.connOpen();
                QSqlQuery* savequery= new QSqlQuery(connection.pdatabase);
                savequery->prepare("INSERT INTO savemoves(PieceColour,PieceName,PiecePresent,PiecePosition,username) VALUES ('"+pieceColour+"','"+piecename+"','"+piecePresent+"','"+saveposition+"','"+playersturn+"')");
                if (savequery->exec())
                {
                    QMessageBox message;
                    message.setText("Your Game unable to save");
                    message.exec();
                    connection.connClose();
                }
                else
                {
                    QMessageBox message;
                     message.setText("Your Game was unable to save.");
                      message.exec();
               }
            }

        }
    }


}


// draws the accessories of the chess board
void accessories(QWidget *baseWidget)
{



    //player1 picture
    QLabel *player1 = new QLabel(baseWidget);
    player1->setGeometry(100,500,100,100);
    player1->setPixmap(QPixmap(":/eachpiece/profile.png"));
    QLabel *name1 = new QLabel(player1username, baseWidget);
    name1->setGeometry(125,610,80,20);

     //player2 picture
    QLabel *player2 = new QLabel(baseWidget);
    player2->setGeometry(100,100,100,100);
    player2->setPixmap(QPixmap(":/eachpiece/profile.png"));
    QLabel *name2 = new QLabel(player2username, baseWidget);
    name2->setGeometry(125,210,80,20);

    //player1 status
    QLabel *player1status1 = new QLabel(player1username + " it's your turn.",baseWidget);
    player1status1->setGeometry(180,620,150,50);
    player1status1->setStyleSheet("font-weight: bold; color: red");

     //player2 picture
    QLabel *player2status2 = new QLabel(player2username + " it's your turn.",baseWidget);
    player2status2->setGeometry(190,220,150,50);
    player2status2->setStyleSheet("font-weight: bold; color: red");




}

//discolours the path of the walls highlighted orange.
void disOrange()
{
    int i;
    for(i=0;i<=max;i++)
        //changes the colour from orange to the original colour of the walls.
        tile[expw[i]/8][expw[i]%8]->wallDisplay();

}



//loads up the board from the databse.
void load(walls *tile[8][8])
{
    QString PieceColour,PieceName,PiecePresent,PiecePosition,player;


    //redraws the chess window.
    QWidget *myWidget=new QWidget();
    myWidget->setGeometry(0,0,1370,700);

    int i,j,k=0,hor,ver;
    Border *border[4]={ NULL };


    //redraws the borderDisplay
    {
    border[0]->outline(myWidget,330,105,0);
    border[1]->outline(myWidget,330,637,0);
    border[2]->outline(myWidget,330,125,1);
    border[2]->outline(myWidget,862,125,1);
    }

    //Create 64 tiles (allocating memories to the objects of Tile class)
    ver=125;
    for(i=0;i<8;i++)
    {
        hor=350;
        for(j=0;j<8;j++)
        {
            //empty squares
            tile[i][j] = new walls(myWidget);
            tile[i][j]->tileColor=(i+j)%2; //takes the remainder
            tile[i][j]->piece=0;
            tile[i][j]->row=i;
            tile[i][j]->col=j;
            tile[i][j]->tileNum=k++;
            tile[i][j]->wallDisplay();
            tile[i][j]->setGeometry(hor,ver,64,64);
            hor+=64;
            //loaded squares of pieces.

        }
        ver+=64;

    }


    wR=7;
    wC=4;

    bR=0;
    bC=4;




    // to load the chess board
    savemoves connection;

    ver=125;
    for(i=0;i<8;i++)
    {
        hor=350;
        for(j=0;j<8;j++)
        {
            connection.connOpen();
            QSqlQuery* query = new QSqlQuery(connection.pdatabase);
            query->exec("select * from savemoves where PieceColour ='"+PieceColour+"', PieceName ='"+PieceName+"', PiecePresent ='"+PiecePresent+"', PiecePosition ='"+PiecePosition+"',username ='"+player+"'");
            qDebug()<<"loaded";

            while(query->next())
            {

                tile[i][j] = new walls(myWidget);
                tile[i][j]->tileColor=(i+j)%2;
                tile[i][j]->piece=1;

                if(PiecePosition==0)
                {
                    tile[i][j]->tileNum=0;
                }

                if(PiecePosition==1)
                {
                    tile[i][j]->tileNum=1;
                }

                if(PiecePosition==2)
                {
                    tile[i][j]->tileNum=2;
                }

                if(PiecePosition==3)
                {
                    tile[i][j]->tileNum=3;
                }

                if(PiecePosition==4)
                {
                    tile[i][j]->tileNum=4;
                }

                if(PiecePosition==5)
                {
                    tile[i][j]->tileNum=5;
                }

                if(PiecePosition==6)
                {
                    tile[i][j]->tileNum=6;
                }

                if(PiecePosition==7)
                {
                    tile[i][j]->tileNum=7;
                }

                else if(PiecePosition==8)
                {
                    tile[i][j]->tileNum=8;
                }

                else if(PiecePosition==9)
                {
                    tile[i][j]->tileNum=9;
                }

                else if(PiecePosition==10)
                {
                    tile[i][j]->tileNum=10;
                }

                else if(PiecePosition==11)
                {
                    tile[i][j]->tileNum=11;
                }

                else if(PiecePosition==12)
                {
                    tile[i][j]->tileNum=12;
                }
                else if(PiecePosition==13)
                {
                    tile[i][j]->tileNum=13;
                }

                else if(PiecePosition==14)
                {
                    tile[i][j]->tileNum=14;
                }

                else if(PiecePosition==15)
                {
                    tile[i][j]->tileNum=15;
                }

                else if(PiecePosition==16)
                {
                    tile[i][j]->tileNum=16;
                }

                else if(PiecePosition==17)
                {
                    tile[i][j]->tileNum=17;
                }

                else if(PiecePosition==18)
                {
                    tile[i][j]->tileNum=18;
                }

                else if(PiecePosition==19)
                {
                    tile[i][j]->tileNum=19;
                }

                else if(PiecePosition==20)
                {
                    tile[i][j]->tileNum=20;
                }

                else if(PiecePosition==21)
                {
                    tile[i][j]->tileNum=21;
                }

                else if(PiecePosition==22)
                {
                    tile[i][j]->tileNum=22;
                }

                else if(PiecePosition==23)
                {
                    tile[i][j]->tileNum=23;
                }

                else if(PiecePosition==24)
                {
                    tile[i][j]->tileNum=24;
                }

                else if(PiecePosition==25)
                {
                    tile[i][j]->tileNum=25;
                }

                else if(PiecePosition==26)
                {
                    tile[i][j]->tileNum=26;
                }

                else if(PiecePosition==27)
                {
                    tile[i][j]->tileNum=27;
                }

                else if(PiecePosition==28)
                {
                    tile[i][j]->tileNum=28;
                }

                else if(PiecePosition==29)
                {
                    tile[i][j]->tileNum=29;
                }

                else if(PiecePosition==30)
                {
                    tile[i][j]->tileNum=30;
                }

                else if(PiecePosition==31)
                {
                    tile[i][j]->tileNum=31;
                }

                else if(PiecePosition==32)
                {
                    tile[i][j]->tileNum=32;
                }

                else if(PiecePosition==33)
                {
                    tile[i][j]->tileNum=33;
                }

                else if(PiecePosition==34)
                {
                    tile[i][j]->tileNum=34;
                }

                else if(PiecePosition==35)
                {
                    tile[i][j]->tileNum=35;
                }

                else if(PiecePosition==36)
                {
                    tile[i][j]->tileNum=36;
                }

                else if(PiecePosition==37)
                {
                    tile[i][j]->tileNum=37;
                }

                else if(PiecePosition==38)
                {
                    tile[i][j]->tileNum=38;
                }

                else if(PiecePosition==39)
                {
                    tile[i][j]->tileNum=39;
                }

                else if(PiecePosition==40)
                {
                    tile[i][j]->tileNum=40;
                }

                else if(PiecePosition==41)
                {
                    tile[i][j]->tileNum=41;
                }

                else if(PiecePosition==42)
                {
                    tile[i][j]->tileNum=42;
                }

                else if(PiecePosition==43)
                {
                    tile[i][j]->tileNum=43;
                }

                else if(PiecePosition==44)
                {
                    tile[i][j]->tileNum=44;
                }

                else if(PiecePosition==45)
                {
                    tile[i][j]->tileNum=45;
                }

                else if(PiecePosition==46)
                {
                    tile[i][j]->tileNum=46;
                }

                else if(PiecePosition==47)
                {
                    tile[i][j]->tileNum=47;
                }

                else if(PiecePosition==48)
                {
                    tile[i][j]->tileNum=48;
                }

                else if(PiecePosition==49)
                {
                    tile[i][j]->tileNum=49;
                }

                else if(PiecePosition==50)
                {
                    tile[i][j]->tileNum=50;
                }

                else if(PiecePosition==51)
                {
                    tile[i][j]->tileNum=51;
                }

                else if(PiecePosition==52)
                {
                    tile[i][j]->tileNum=52;
                }

                else if(PiecePosition==53)
                {
                    tile[i][j]->tileNum=53;
                }

                else if(PiecePosition==54)
                {
                    tile[i][j]->tileNum=54;
                }

                else if(PiecePosition==55)
                {
                    tile[i][j]->tileNum=55;
                }

                else if(PiecePosition==56)
                {
                    tile[i][j]->tileNum=56;
                }

                else if(PiecePosition==57)
                {
                    tile[i][j]->tileNum=57;
                }

                else if(PiecePosition==58)
                {
                    tile[i][j]->tileNum=58;
                }

                else if(PiecePosition==59)
                {
                    tile[i][j]->tileNum=59;
                }

                else if(PiecePosition==60)
                {
                    tile[i][j]->tileNum=60;
                }

                else if(PiecePosition==61)
                {
                    tile[i][j]->tileNum=61;
                }

                else if(PiecePosition==62)
                {

                    tile[i][j]->tileNum=62;
                }

                else if(PiecePosition==63)
                {
                    tile[i][j]->tileNum=63;
                }

                tile[i][j]->wallDisplay();
                tile[i][j]->setGeometry(hor,ver,64,64);

                if(PieceColour=="W")
                {
                    tile[i][j]->pieceColor=1;
                    player1username=player;
                }
                else if(PieceColour=="B")
                {
                    tile[i][j]->pieceColor=0;
                    player2username=player;
                }


                if (PieceName=="S")
                {
                    tile[i][j]->pieceName='S';
                     tile[i][j]->display('S');
                }
                else if (PieceName=="B")
                {
                   tile[i][j]->pieceName='B';
                     tile[i][j]->display('B');

                }

                else if (PieceName=="W")
                {
                    tile[i][j]->pieceName='W';
                     tile[i][j]->display('W');
                }

                else if (PieceName=="P")
                {
                    tile[i][j]->pieceName='P';
                     tile[i][j]->display('P');
                }
                else if (PieceName=="Z")
                {
                    tile[i][j]->pieceName='Z';
                     tile[i][j]->display('Z');
                }

                else if (PieceName=="H")
                {
                    tile[i][j]->pieceName='H';
                     tile[i][j]->display('H');
                }




                 hor+=64;
                 connection.connClose();
            }
            ver+=64;

        }
    }





    accessories(myWidget);
    buttongoback(myWidget);
    buttonUndo(myWidget);
    savebutton(myWidget);
    HowtoPlayInfo(myWidget);
    myWidget->show();

}

//on new game it loads up the saved game from databse.
void gamestatus::on_newgame_clicked()
{

    if (player1username.contains("") && player2username.contains(""))
    {

        QWidget *myWidget=new QWidget();
        myWidget->setGeometry(0,0,1370,700);
        accessories(myWidget);
        chessBoard(myWidget,tile);
        buttongoback(myWidget);
        buttonUndo(myWidget);
        savebutton(myWidget);
        HowtoPlayInfo(myWidget);
        myWidget->show();
        this->hide();
    }

}

//on gamestatus go back button cllicked it would take it back to the
void gamestatus::on_goback_clicked()
{
    this->hide();
    ScreenWindow *newusermainscreen;
    newusermainscreen = new ScreenWindow(this);
    newusermainscreen -> show();
}

//once current game has been clicked it will run the load function.
void gamestatus::on_currentgame_clicked()
{
    this->hide();
   load(tile);
}





