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

void Food::generateFood( objPosArrayList &playerPosList)
{

    if (!foodGenerated)
    {
        do
        {
            rnx = rand() % (gameMechs.getBoardSizeX()-2)+1;
            rny = rand() % (gameMechs.getBoardSizeY()-2)+1;
            
            overlap = false;
            objPos tempPos;

            for (int i =0 ; i<playerPosList.getSize(); i++)
            {
                playerPosList.getElement(tempPos,i);

                if(tempPos.x == rnx && tempPos.y == rny)
                {
                    overlap = true;
                    break;
                }
            }

        } while (overlap);

        foodPos.setObjPos(rnx, rny, 'O');
        foodGenerated = true;
    }
}
    

void Food::getFoodPos(objPos &returnPos)
{
    foodPos.getObjPos(returnPos);
}


