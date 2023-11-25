#include "Food.h"
#include "GameMechs.h"
#include <time.h>
#include <stdlib.h>
#include "objPos.h"

Food::Food(GameMechs &gm) : gameMechs(gm)
{
    foodSymbol = 'o';
}

Food:: ~Food()
{

}

void Food::resetFood()
{
    foodGenerated = false;
}

void Food::generateFood(objPos blockOff)
{

    if (!foodGenerated)
    {
        do
        {
            rnx = rand() % (gameMechs.getBoardSizeX()-2)+1;
            rny = rand() % (gameMechs.getBoardSizeY()-2)+1;
        } while (rnx == blockOff.x && rny == blockOff.y);

        foodPos.setObjPos(rnx, rny, 'o');
        foodGenerated = true;
    }
}
    

void Food::getFoodPos(objPos &returnPos)
{
    foodPos.getObjPos(returnPos);
}

