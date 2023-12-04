#include "Food.h"
#include "GameMechs.h"
#include <time.h>
#include <stdlib.h>
#include "objPos.h"

Food::Food(GameMechs &gm) : gameMechs(gm) //default constructor initializing member variables. --> : gameMechs(gm) initializes gameMechs with value of gm param.
{
    foodSymbol = 'o';
    foodPos.x = 0;
    foodPos.y = 0;
}

Food:: ~Food()
{

}

void Food::resetFood() //resets foodgenerated bool
{
    foodGenerated = false;
}

void Food::generateFood( objPosArrayList &playerPosList)
{

    if (!foodGenerated)
    {
        do
        {
            rnx = rand() % (gameMechs.getBoardSizeX()-2)+1; // generate random coords for food within gameboard
            rny = rand() % (gameMechs.getBoardSizeY()-2)+1;
            
            overlap = false;
            objPos tempPos;

            for (int i =0 ; i<playerPosList.getSize(); i++) //checks if randomly generated pos overlaps with playerpos
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


