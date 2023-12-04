#ifndef FOOD_H
#define FOOD_H
#include "objPos.h"
using namespace std;
#include "GameMechs.h"

class Food
{

    private:
        objPos foodPos;
        int rnx; //random x coordinate for generating food
        int rny; //random y coordinate for generating food
        char foodSymbol;
        GameMechs &gameMechs;//reference to game mechanics
        bool foodGenerated; 
        bool overlap; 


    public:
        Food(GameMechs &gm); //default constructor takes reference to game mechanics class
        ~Food();

        void generateFood( objPosArrayList &playerPosList); //for generating food and avoiding player position

        void getFoodPos(objPos &returnPos); 

        void resetFood(); 



};

#endif