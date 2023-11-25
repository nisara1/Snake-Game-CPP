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


    public:
        Food(GameMechs &gm);
        ~Food();

        void generateFood(objPos blockOff);

        void getFoodPos(objPos &returnPos);

        void resetFood();



};

#endif