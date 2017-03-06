//#include "movesvalidation.h"

//extern int expa[60];

//movesvalidation::movesvalidation()
//{

//}

//int movesvalidation::chooser(chessboard1 *temp)
//{
//    switch(temp->pieceName)
//    {
//    case 'P': flag=validatePawn(temp);
//              break;

//    case 'R': flag=validateRook(temp);
//              break;

//    case 'H': flag=validateHorse(temp);
//              break;

//    case 'K': flag=validateKing(temp);
//              break;

//    case 'Q': flag=validateQueen(temp);
//              break;

//    case 'B': flag=validateBishop(temp);
//              break;

//    }

//    orange();

//    return flag;
//}

//PAWN
//int movesvalidation::validatePawn(chessboard1 *temp)
//{
//    int row,col;

//    row=temp->row;
//    col=temp->col;
//    retVal=0;

//    //White Pawn
//    if(temp->pieceColor)
//    {
//        if(row-1>=0 && !wall[row-1][col]->piece)
//        {
//            expo[max++]=wall[row-1][col]->wallNum;
//            retVal=1;
//        }

//        if(row==6 && !wall[5][col]->piece && !wall[4][col]->piece)
//        {
//            expo[max++]=wall[row-2][col]->wallNum;
//            retVal=1;
//        }

//        if(row-1>=0 && col-1>=0)
//        {
//            if(wall[row-1][col-1]->pieceColor!=temp->pieceColor && wall[row-1][col-1]->piece)
//            {
//            expo[max++]=wall[row-1][col-1]->wallNum;
//            retVal=1;
//            }
//        }

//        if(row-1>=0 && col+1<=7)
//        {
//            if(wall[row-1][col+1]->pieceColor!=temp->pieceColor && wall[row-1][col+1]->piece)
//            {
//                expo[max++]=wall[row-1][col+1]->wallNum;
//                retVal=1;
//            }
//        }
//    }
//    else
//    {
//        if(row+1<=7 && !wall[row+1][col]->piece)
//        {
//            expo[max++]=wall[row+1][col]->wallNum;
//            retVal=1;
//        }

//        if(row==1 && !wall[2][col]->piece && !wall[3][col]->piece)
//        {
//            expo[max++]=wall[row+2][col]->wallNum;
//            retVal=1;
//        }

//        if(row+1<=7 && col-1>=0)
//        {
//            if(wall[row+1][col-1]->pieceColor!=temp->pieceColor && wall[row+1][col-1]->piece)
//            {
//                expo[max++]=wall[row+1][col-1]->wallNum;
//                retVal=1;
//            }
//        }

//        if(row+1<=7 && col+1<=7)
//        {
//            if(wall[row+1][col+1]->pieceColor!=temp->pieceColor && wall[row+1][col+1]->piece)
//            {
//                expo[max++]=wall[row+1][col+1]->wallNum;
//                retVal=1;
//            }
//        }
//    }

//    return retVal;
//}


////ROOK
//int movesvalidation::validateRook(chessboard1 *temp)
//{
//    int r,c;

//    retVal=0;

//    r=temp->row;
//    c=temp->col;
//    while(r-->0)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r++<7)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(c++<7)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(c-->0)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }


//    return retVal;
//}


////HORSE
//int movesvalidation::validateHorse(chessboard1 *temp)
//{
//    int r,c;
//    retVal=0;

//    r=temp->row;
//    c=temp->col;

//    if(r-2>=0 && c-1>=0)
//    {
//        if(wall[r-2][c-1]->pieceColor!=temp->pieceColor || !wall[r-2][c-1]->piece)
//        {
//            expo[max++]=wall[r-2][c-1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r-2>=0 && c+1<=7)
//    {
//        if(wall[r-2][c+1]->pieceColor!=temp->pieceColor || !wall[r-2][c+1]->piece)
//        {
//            expo[max++]=wall[r-2][c+1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r-1>=0 && c-2>=0)
//    {
//        if(wall[r-1][c-2]->pieceColor!=temp->pieceColor || !wall[r-1][c-2]->piece)
//        {
//            expo[max++]=wall[r-1][c-2]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r-1>=0 && c+2<=7)
//    {
//        if(wall[r-1][c+2]->pieceColor!=temp->pieceColor || !wall[r-1][c+2]->piece)
//        {
//            expo[max++]=wall[r-1][c+2]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r+2<=7 && c+1<=7)
//    {
//        if(wall[r+2][c+1]->pieceColor!=temp->pieceColor || !wall[r+2][c+1]->piece)
//        {
//            expo[max++]=wall[r+2][c+1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r+2<=7 && c-1>=0)
//    {
//        if(wall[r+2][c-1]->pieceColor!=temp->pieceColor || !wall[r+2][c-1]->piece)
//        {
//            expo[max++]=wall[r+2][c-1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r+1<=7 && c-2>=0)
//    {
//        if(wall[r+1][c-2]->pieceColor!=temp->pieceColor || !wall[r+1][c-2]->piece)
//        {
//            expo[max++]=wall[r+1][c-2]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r+1<=7 && c+2<=7)
//    {
//        if(wall[r+1][c+2]->pieceColor!=temp->pieceColor || !wall[r+1][c+2]->piece)
//        {
//            expo[max++]=wall[r+1][c+2]->wallNum;
//            retVal=1;
//        }
//    }

//    return retVal;
//}


////KING
//int movesvalidation::validateKing(chessboard1 *temp)
//{
//    int r,c;
//    retVal=0;

//    r=temp->row;
//    c=temp->col;

//    if(r-1>=0)
//    {
//        if(!wall[r-1][c]->piece || wall[r-1][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r-1][c]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r+1<=7)
//    {
//        if(!wall[r+1][c]->piece || wall[r+1][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r+1][c]->wallNum;
//            retVal=1;
//        }
//    }

//    if(c-1>=0)
//    {
//        if(!wall[r][c-1]->piece || wall[r][c-1]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c-1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(c+1<=7)
//    {
//        if(!wall[r][c+1]->piece || wall[r][c+1]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c+1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r-1>=0 && c-1>=0)
//    {
//        if(!wall[r-1][c-1]->piece || wall[r-1][c-1]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r-1][c-1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r-1>=0 && c+1<=7)
//    {
//        if(!wall[r-1][c+1]->piece || wall[r-1][c+1]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r-1][c+1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r+1<=7 && c-1>=0)
//    {
//        if(!wall[r+1][c-1]->piece || wall[r+1][c-1]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r+1][c-1]->wallNum;
//            retVal=1;
//        }
//    }

//    if(r+1<=7 && c+1<=7)
//    {
//        if(!wall[r+1][c+1]->piece || wall[r+1][c+1]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r+1][c+1]->wallNum;
//            retVal=1;
//        }
//    }

//    return retVal;
//}


////QUEEN
//int movesvalidation::validateQueen(chessboard1 *temp)
//{
//    int r,c;

//    retVal=0;

//    r=temp->row;
//    c=temp->col;
//    while(r-->0)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r++<7)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(c++<7)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(c-->0)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r-->0 && c++<7)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r-->0 && c-->0)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r++<7 && c++<7)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r++<7 && c-->0)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }


//    return retVal;
//}

////BISHOP
//int movesvalidation::validateBishop(chessboard1 *temp)
//{
//    int r,c;
//    retVal=0;

//    r=temp->row;
//    c=temp->col;
//    while(r-->0 && c++<7)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r-->0 && c-->0)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r++<7 && c++<7)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    r=temp->row;
//    c=temp->col;
//    while(r++<7 && c-->0)
//    {
//        if(!wall[r][c]->piece)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//        }

//        else if(wall[r][c]->pieceColor==temp->pieceColor)
//            break;

//        else if(wall[r][c]->pieceColor!=temp->pieceColor)
//        {
//            expo[max++]=wall[r][c]->wallNum;
//            retVal=1;
//            break;
//        }
//    }

//    return retVal;
//}

//int movesvalidation::check(chessboard1 *temp)
//{
//    int r,c,flag;
//    retVal=0;

//    return retVal;
//}

//void movesvalidation::orange()
//{
//    int i,n;

//    for(i=0;i<max;i++)
//        wall[expo[i]/8][expo[i]%8]->setStyleSheet("QLabel {background-color: orange;}");
//}
