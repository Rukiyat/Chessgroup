#include "walls.h"
#include "validatemoves.h"
#include "gamestatus.h"


extern int count,turn;
extern walls *click1;
extern walls *tile[8][8];

void walls::display(char elem)
{
    this->pieceName=elem;

    //White pieces
    if(this->pieceColor && this->piece)
    {
        switch(elem)
        {
            // S for Soldier piece
            case 'S': this->setPixmap(QPixmap(":/eachpiece/pawn_white.svg"));
                      break;

            // B for Bomb piece
            case 'B': this->setPixmap(QPixmap(":/eachpiece/rook_white.svg"));
                      break;

            // H for Horse piece
            case 'H': this->setPixmap(QPixmap(":/eachpiece/knight_white.svg"));
                      break;

            // Z for Wizard piece
            case 'Z': this->setPixmap(QPixmap(":/eachpiece/king_white.svg"));
                      break;

            // W for Witch piece
            case 'W': this->setPixmap(QPixmap(":/eachpiece/queen_white.svg"));
                      break;

            // P for Priest piece
            case 'P': this->setPixmap(QPixmap(":/eachpiece/bishop_white.svg"));
                      break;;
        }
    }

    //Black pieces
    else if(this->piece)
    {
        switch(elem)
        {
        // S for Soldier piece
        case 'S': this->setPixmap(QPixmap(":/eachpiece/pawn_black.svg"));
                  break;

        // B for Bomb piece
        case 'B': this->setPixmap(QPixmap(":/eachpiece/rook_black.svg"));
                  break;

        // H for Horse piece
        case 'H': this->setPixmap(QPixmap(":/eachpiece/knight_black.svg"));
                  break;

        // Z for Wizard piece
        case 'Z': this->setPixmap(QPixmap(":/eachpiece/king_black.svg"));
                  break;

        // W for Witch piece
        case 'W': this->setPixmap(QPixmap(":/eachpiece/queen_black.svg"));
                  break;

        // P for Priest piece
        case 'P': this->setPixmap(QPixmap(":/eachpiece/bishop_black.svg"));
                  break;
        }
    }
    else
        this->clear();
}



//highlights the path of the piece that is movable.
void walls::wallDisplay()
{

    if(this->tileColor)
        this->setStyleSheet("QLabel {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(164, 164, 164, 255), stop:1 rgba(255, 255, 255, 255));\n}");
    else
        this->setStyleSheet("QLabel {background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n}");
}

