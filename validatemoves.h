#ifndef VALIDATEMOVES_H
#define VALIDATEMOVES_H
#include "walls.h"

extern walls *tile[8][8];
extern int expw[60],max,wR,wC;
class validatemoves
{
    int flag,retVal;
public:
    validatemoves();
    int chooser(walls *temp);
    int validateBishop(walls *temp);
    int validateQueen(walls *temp);
    int validateKing(walls *temp);
    int validateHorse(walls *temp);
    int validateRook(walls *temp);
    int validatePawn(walls *temp);
    void orange();
    int check(walls *temp);
};

#endif // VALIDATEMOVES_H
