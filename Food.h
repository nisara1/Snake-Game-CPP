#ifndef FOOD_H
#define FOOD_H
#include "objPos.h"
using namespace std;
#include "GameMechs.h"

class Food
{

    private:
        objPos foodPos;
        int rnx;
        int rny;
        char foodSymbol;
        GameMechs &gameMechs;
        bool foodGenerated;
        bool overlap;


    public:
        Food(GameMechs &gm);
        ~Food();

        void generateFood( objPosArrayList &playerPosList); //need to upgrade this. Need to accept player body array list. Go through each array list element to make sure they are all blocked off from random food generation

        void getFoodPos(objPos &returnPos);

        void resetFood();



};

#endif