#include "gamestatus.h"
#include "ui_gamestatus.h"
#include "walls.h"
#include "multiplayerlogin.h"
#include "loginuser.h"
#include <QPushButton>

extern QString player1username, player2username;

GameStatus::GameStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameStatus)
{
    ui->setupUi(this);

}

GameStatus::~GameStatus()
{
    delete ui;
}

//void GameStatus::on_newgame_clicked()
//{

//    this->hide();
//    chessboard.show();


//}


//void GameStatus::on_newgame_clicked(bool checked)
//{

//    if((checked=2))
//    {
//        this->show();
//        chessboard.show();

//    }
//}
int count=0, turn=1, expw[60], max=0;
int wR,wC,bR,bC;
walls *click1;

walls *tile[8][8] = { { NULL } };

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

void buttongoback(QWidget *baseWidget)
{
    QPushButton *go = new QPushButton(baseWidget);
    go->setGeometry(0,670,100,30);
    go->setText("<- GOBACK");
    go->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(164, 164, 164, 255), stop:1 rgba(255, 255, 255, 255));");
    QObject::connect(go, SIGNAL (clicked()), qApp, SLOT(gogoback()));
}
void gogoback()
{
    GameStatus *gaming;
    gaming = new GameStatus;
    gaming->show();
}


void accessories(QWidget *baseWidget)
{
    QLabel *player2 = new QLabel(baseWidget);
    QLabel *name2 = new QLabel(player2username, baseWidget);
    QLabel *time2 = new QLabel("00:00:00", baseWidget);

    QLabel *player1 = new QLabel(baseWidget);
    QLabel *name1 = new QLabel(player1username, baseWidget);
    QLabel *time1 = new QLabel("00:00:00", baseWidget);

    QLabel *moves = new QLabel(baseWidget);

    name1->setGeometry(125,610,80,20);
    time1->setGeometry(110,635,80,20);
    player1->setGeometry(100,500,100,100);
    player1->setPixmap(QPixmap(":/eachpiece/profile.png"));


    name2->setGeometry(125,210,80,20);
    time2->setGeometry(120,235,80,20);
    player2->setGeometry(100,100,100,100);
    player2->setPixmap(QPixmap(":/eachpiece/profile.png"));

    QLabel *player1status1 = new QLabel(player1username + " it's your turn.", baseWidget);
    player1status1->setGeometry(180,620,150,50);
    player1status1->setStyleSheet("font-weight: bold; color: red");
//    player1status1->hide();

    QLabel *player2status2 = new QLabel(player2username + " it's your turn.", baseWidget);
    player2status2->setGeometry(190,220,150,50);
    player2status2->setStyleSheet("font-weight: bold; color: red");
//    player2status2->hide();

    moves->setGeometry(1000,105,250,550);
    moves->setStyleSheet("QLabel {background-color: white;}");

}

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

    //white pawns
    for(j=0;j<8;j++)
    {
        tile[1][j]->piece=1;
        tile[1][j]->pieceColor=0;
        tile[1][j]->display('P');
    }

    //black pawns
    for(j=0;j<8;j++)
    {
        tile[6][j]->piece=1;
        tile[6][j]->pieceColor=1;
        tile[6][j]->display('P');
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
    tile[0][0]->display('R');
    tile[0][1]->display('H');
    tile[0][2]->display('B');
    tile[0][3]->display('Q');
    tile[0][4]->display('K');
    tile[0][5]->display('B');
    tile[0][6]->display('H');
    tile[0][7]->display('R');
    }


    {
    tile[7][0]->display('R');
    tile[7][1]->display('H');
    tile[7][2]->display('B');
    tile[7][3]->display('Q');
    tile[7][4]->display('K');
    tile[7][5]->display('B');
    tile[7][6]->display('H');
    tile[7][7]->display('R');
    }

    wR=7;
    wC=4;

    bR=0;
    bC=4;

}

void GameStatus::on_newgame_clicked()
{

    if (player1username.contains("") && player2username.contains(""))
    {
        QWidget *myWidget = new QWidget();
        myWidget->setGeometry(0,0,1370,700);

        accessories(myWidget);
        chessBoard(myWidget,tile);
        buttongoback(myWidget);

        myWidget->show();
        this->hide();
    }

}

void GameStatus::on_goback_clicked()
{
    this->hide();
    loginuser *login;
    login = new loginuser(this);
    login->show();
}
