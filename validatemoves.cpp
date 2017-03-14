#include "validatemoves.h"
#include <QDebug>

validatemoves::validatemoves()
{

}
//switch base case to validate which ever piece that has been clicked on.
int validatemoves::chooser(walls *temp)
{
    switch(temp->pieceName)
    {
    case 'P': flag=validatePawn(temp);
              break;

    case 'R': flag=validateRook(temp);
              break;

    case 'H': flag=validateHorse(temp);
              break;

    case 'K': flag=validateKing(temp);
              break;

    case 'Q': flag=validateQueen(temp);
              break;

    case 'B': flag=validateBishop(temp);
              break;

    }

    orange();

    return flag;
}

//PAWN
int validatemoves::validatePawn(walls *temp)
{
    int row,col;

    row=temp->row;
    col=temp->col;
    retVal=0;





    if(temp->pieceColor)
    {
        //White Pawn first move two possible squares.
        if(row-1>=0 && !tile[row-1][col]->piece)
        {
            expw[max++]=tile[row-1][col]->tileNum;

            retVal=1;

        }
        //white pawn move after first move, one square at a time.
        if(row==6 && !tile[5][col]->piece && !tile[4][col]->piece)
        {
            expw[max++]=tile[row-2][col]->tileNum;
            retVal=1;

        }

        //white pawn capturing a black pawn
        if(row-1>=0 && col-1>=0)
        {
            if(tile[row-1][col-1]->pieceColor!=temp->pieceColor && tile[row-1][col-1]->piece)
            {
            expw[max++]=tile[row-1][col-1]->tileNum;
            retVal=1;

            }
        }

        //white pawn capturing other pieces besides black pawn.
        if(row-1>=0 && col+1<=7)
        {
            if(tile[row-1][col+1]->pieceColor!=temp->pieceColor && tile[row-1][col+1]->piece)
            {
                expw[max++]=tile[row-1][col+1]->tileNum;
                retVal=1;
            }
        }
    }

    else
    {
        //black pawn first move can move two squares ahead
        if(row+1<=7 && !tile[row+1][col]->piece)
        {
            expw[max++]=tile[row+1][col]->tileNum;
            retVal=1;


        }
//black pawn move after first move can move one square ahead each time
        if(row==1 && !tile[2][col]->piece && !tile[3][col]->piece)
        {
            expw[max++]=tile[row+2][col]->tileNum;
            retVal=1;


        }
//if black pawn captures white pawn.
        if(row+1<=7 && col-1>=0)
        {
            if(tile[row+1][col-1]->pieceColor!=temp->pieceColor && tile[row+1][col-1]->piece)
            {
                expw[max++]=tile[row+1][col-1]->tileNum;
                retVal=1;
            }
        }

//if black pawn captures any piece besides white pawn.
        if(row+1<=7 && col+1<=7)
        {
            if(tile[row+1][col+1]->pieceColor!=temp->pieceColor && tile[row+1][col+1]->piece)
            {
                expw[max++]=tile[row+1][col+1]->tileNum;
                retVal=1;

            }
        }
    }


    return retVal;
}


//ROOK
int validatemoves::validateRook(walls *temp)
{
    int r,c;

    retVal=0;
    //White rook
    r=temp->row;
    c=temp->col;

    //when rook is moving upwards
    while(r-->0)
    {
        //Rook moves any number of squares upwards as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the rook piece is moving upwards and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Rook captures opponent piece above it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    //when rook is moving downwards
    while(r++<7)
    {
        //Rook moves any number of squares downwards as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the rook piece is moving downwards and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Rook captures opponent piece below it
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;


    // when rook is moving to the right
    while(c++<7)
    {
        //Rook moves any number of squares to the right as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the rook piece is moving to the right and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Rook captures opponent piece to the right of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    // when rook is moving to the left
    while(c-->0)
    {
        //Rook moves any number of squares to the left as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the rook piece is moving to the left and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

       //Rook captures opponent piece to the left of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }


    return retVal;
}


//HORSE
int validatemoves::validateHorse(walls *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;

    //horse moving upwards two squares to the left
    if(r-2>=0 && c-1>=0)
    {
        if(tile[r-2][c-1]->pieceColor!=temp->pieceColor || !tile[r-2][c-1]->piece)
        {
            expw[max++]=tile[r-2][c-1]->tileNum;
            retVal=1;
        }
    }

    //horse moving upwards two squares to the right;
    if(r-2>=0 && c+1<=7)
    {
        if(tile[r-2][c+1]->pieceColor!=temp->pieceColor || !tile[r-2][c+1]->piece)
        {
            expw[max++]=tile[r-2][c+1]->tileNum;
            retVal=1;
        }
    }

    //horse moving one square to the left
    if(r-1>=0 && c-2>=0)
    {
        if(tile[r-1][c-2]->pieceColor!=temp->pieceColor || !tile[r-1][c-2]->piece)
        {
            expw[max++]=tile[r-1][c-2]->tileNum;
            retVal=1;

        }
    }

    //horse upwards one square to the right
    if(r-1>=0 && c+2<=7)
    {
        if(tile[r-1][c+2]->pieceColor!=temp->pieceColor || !tile[r-1][c+2]->piece)
        {
            expw[max++]=tile[r-1][c+2]->tileNum;
            retVal=1;

        }
    }

    //horse moving downwards one square to the right
    if(r+2<=7 && c+1<=7)
    {
        if(tile[r+2][c+1]->pieceColor!=temp->pieceColor || !tile[r+2][c+1]->piece)
        {
            expw[max++]=tile[r+2][c+1]->tileNum;
            retVal=1;
        }
    }
    //horse moving downwards two squares to the left
    if(r+2<=7 && c-1>=0)
    {
        if(tile[r+2][c-1]->pieceColor!=temp->pieceColor || !tile[r+2][c-1]->piece)
        {
            expw[max++]=tile[r+2][c-1]->tileNum;
            retVal=1;
        }
    }
    //horse moving downwards to the left one square.
    if(r+1<=7 && c-2>=0)
    {
        if(tile[r+1][c-2]->pieceColor!=temp->pieceColor || !tile[r+1][c-2]->piece)
        {
            expw[max++]=tile[r+1][c-2]->tileNum;
            retVal=1;
        }
    }


    //horse capturing a piece and one square from an enemy opponent.
    if(r+1<=7 && c+2<=7)
    {
        if(tile[r+1][c+2]->pieceColor!=temp->pieceColor || !tile[r+1][c+2]->piece)
        {
            expw[max++]=tile[r+1][c+2]->tileNum;
            retVal=1;
        }
    }

    return retVal;
}


//KING
int validatemoves::validateKing(walls *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;

    // king moves upwards by one square
    if(r-1>=0)
    {
        if(!tile[r-1][c]->piece || tile[r-1][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r-1][c]->tileNum;
            retVal=1;
        }
    }

    //king moves downwards by one square
    if(r+1<=7)
    {
        if(!tile[r+1][c]->piece || tile[r+1][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r+1][c]->tileNum;
            retVal=1;
        }
    }

    //king moves left by one square
    if(c-1>=0)
    {
        if(!tile[r][c-1]->piece || tile[r][c-1]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c-1]->tileNum;
            retVal=1;
        }
    }

    //king moves right by one square
    if(c+1<=7)
    {
        if(!tile[r][c+1]->piece || tile[r][c+1]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c+1]->tileNum;
            retVal=1;
        }
    }

    //king moves upwards by one square to the left
    if(r-1>=0 && c-1>=0)
    {
        if(!tile[r-1][c-1]->piece || tile[r-1][c-1]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r-1][c-1]->tileNum;
            retVal=1;
        }
    }

    //king move upwards by one square to the right
    if(r-1>=0 && c+1<=7)
    {
        if(!tile[r-1][c+1]->piece || tile[r-1][c+1]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r-1][c+1]->tileNum;
            retVal=1;

        }
    }

    //king moves downwards by one square to the right
    if(r+1<=7 && c-1>=0)
    {
        if(!tile[r+1][c-1]->piece || tile[r+1][c-1]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r+1][c-1]->tileNum;
            retVal=1;
        }
    }

    //king move downwards by one square to the left

    if(r+1<=7 && c+1<=7)
    {
        if(!tile[r+1][c+1]->piece || tile[r+1][c+1]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r+1][c+1]->tileNum;
            retVal=1;
        }
    }

    return retVal;
}


//QUEEN
int validatemoves::validateQueen(walls *temp)
{
    int r,c;

    retVal=0;

    r=temp->row;
    c=temp->col;

    //when queen is moving upwards
    while(r-->0)
    {
        //Queen moves any number of squares upwards as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the queen piece is moving upwards and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

       //Queen captures opponent piece above it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    //when queen is moving downwards
    while(r++<7)
    {
        //Queen moves any number of squares downwards as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the queen piece is moving downwards and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Queen captures opponent piece below it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    // when queen is moving to the right
    while(c++<7)
    {
        //Queen moves any number of squares to the right as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the queen piece is moving to the right and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Queen captures opponent piece to the right of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;


    // when queen is moving to the left
    while(c-->0)
    {
        //Queen moves any number of squares to the left as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the queen piece is moving to the left and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

       //Queen captures opponent piece to the left of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    // when queen is moving upwards and diagonally to the right
    while(r-->0 && c++<7)
    {   //Queen moves upwards any number of squares diagonaly to the right as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the queen piece is moving upwards to the right and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Queen captures opponent piece diagonally to the right and above it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    // when queen is moving upwards and diagonally to the left
    while(r-->0 && c-->0)
    {
         //Queen moves upwards any number of squares diagonally to the left as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the queen piece is moving upwards to the left and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

       //Queen captures opponent piece diagonally to the left and above of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    // when queen is moving downwards and diagonally to the right
    while(r++<7 && c++<7)
    {
        //Queen moves downwards any number of squares diagonally to the right as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the queen piece is moving downwards to the right and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

         //Queen captures opponent piece diagonally to the right and below of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    // when queen is moving downwards and diagonally to the left
    while(r++<7 && c-->0)
    {
        //Queen moves downwards any number of squares diagonally to the left as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the queen piece is moving downwards to the left and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Queen captures opponent piece diagonally to the left and below of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }


    return retVal;
}

//BISHOP
int validatemoves::validateBishop(walls *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;

    //when bishop is moving upwards and diagonally to the right
    while(r-->0 && c++<7)
    {
        //Bishop moves upwards any number of squares diagonaly to the right as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the bishop piece is moving upwards to the right and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Bishop captures opponent piece diagonally to the right and above it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;

        }
    }

    r=temp->row;
    c=temp->col;

    //when bishop is moving upwards and diagonally to the left
    while(r-->0 && c-->0)
    {
        //Bishop moves upwards any number of squares diagonally to the left as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

       //when the bishop piece is moving upwards to the left and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Bishop captures opponent piece diagonally to the left and above of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;

        }
    }

    r=temp->row;
    c=temp->col;

    //when bishop is moving downwards and diagonally to the right
    while(r++<7 && c++<7)
    {
        // Bishop moves downwards any number of squares diagonally to the right as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the bishop piece is moving downwards to the right and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Bishop captures opponent piece diagonally to the right and below of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;

    // when bishop is moving downwards and diagonally to the left
    while(r++<7 && c-->0)
    {
        //Bishop moves downwards any number of squares diagonally to the left as long as there is no piece in it's way
        if(!tile[r][c]->piece)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
        }

        //when the bishop piece is moving downwards to the left and detetcts one of its own it stops.
        else if(tile[r][c]->pieceColor==temp->pieceColor)
            break;

        //Bishop captures opponent piece diagonally to the left and below of it.
        else if(tile[r][c]->pieceColor!=temp->pieceColor)
        {
            expw[max++]=tile[r][c]->tileNum;
            retVal=1;
            break;
        }
    }

    return retVal;
}

//intiliasing the retval to be null at the start of the game
int validatemoves::check(walls *temp)
{
    int r,c,flag;
    retVal=0;

    return retVal;
}

void validatemoves::orange()
{
    int i,n;

    for(i=0;i<max;i++)
        tile[expw[i]/8][expw[i]%8]->setStyleSheet("QLabel {background-color: orange;}");
}
