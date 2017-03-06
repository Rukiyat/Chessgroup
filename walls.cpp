#include "walls.h"
#include "validatemoves.h"




validatemoves *valid = new validatemoves;

extern int count,turn;
extern walls *click1;
extern walls *tile[8][8];


void validate(walls *temp,int c);
void disOrange();

void walls::mousePressEvent(QMouseEvent *event)
{
    validate(this,++count);
}



void walls::display(char elem)
{
    this->pieceName=elem;

    if(this->pieceColor && this->piece)
    {
        switch(elem)
        {
            case 'P': this->setPixmap(QPixmap(":/eachpiece/pawn_white.svg"));
                      break;
            case 'R': this->setPixmap(QPixmap(":/eachpiece/rook_white.svg"));
                      break;
            case 'H': this->setPixmap(QPixmap(":/eachpiece/knight_white.svg"));
                      break;
            case 'K': this->setPixmap(QPixmap(":/eachpiece/king_white.svg"));
                      break;
            case 'Q': this->setPixmap(QPixmap(":/eachpiece/queen_white.svg"));
                      break;
            case 'B': this->setPixmap(QPixmap(":/eachpiece/bishop_white.svg"));
                      break;
        }
    }

    else if(this->piece)
    {
        switch(elem)
        {
        case 'P': this->setPixmap(QPixmap(":/eachpiece/pawn_black.svg"));
                  break;
        case 'R': this->setPixmap(QPixmap(":/eachpiece/rook_black.svg"));
                  break;
        case 'H': this->setPixmap(QPixmap(":/eachpiece/knight_black.svg"));
                  break;
        case 'K': this->setPixmap(QPixmap(":/eachpiece/king_black.svg"));
                  break;
        case 'Q': this->setPixmap(QPixmap(":/eachpiece/queen_black.svg"));
                  break;
        case 'B': this->setPixmap(QPixmap(":/eachpiece/bishop_black.svg"));
                  break;
        }
    }
    else
        this->clear();
}


void validate(walls *temp, int c)
{
    int retValue,i;

    disOrange();

    if(c==1)
    {
        if(temp->piece && (temp->pieceColor==turn))
        {
            expw[max++]=temp->tileNum;
            retValue=valid->chooser(temp);

            if(retValue)
            {
                click1= new walls();
                temp->setStyleSheet("QLabel {background-color: green;}");
                click1=temp;
            }
            else
            {
                temp->setStyleSheet("QLabel {background-color: red;}");
                count=0;
            }
        }
        else
        {

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

        for(i=0;i<max;i++)
        {
            if(temp->tileNum==expw[i])
            {
                click1->piece=0;
                temp->piece=1;

                temp->pieceColor=click1->pieceColor;
                temp->pieceName=click1->pieceName;

                click1->display(click1->pieceName);
                temp->display(click1->pieceName);

                click1->wallDisplay();
                temp->wallDisplay();

                retValue=valid->check(click1);

                if(retValue)
                {
                    tile[wR][wC]->setStyleSheet("QLabel {background-color: red;}");
                }


                disOrange();

                max=0;

                turn=(turn+1)%2;

                count=0;

            }

            else

                count=1;
        }
    }
}

void walls::wallDisplay()
{

    if(this->tileColor)
        this->setStyleSheet("QLabel {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(164, 164, 164, 255), stop:1 rgba(255, 255, 255, 255));\n}");
    else
        this->setStyleSheet("QLabel {background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n}");
}

void disOrange()
{
    int i;
    for(i=0;i<max;i++)
        tile[expw[i]/8][expw[i]%8]->wallDisplay();



}

