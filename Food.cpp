#include "Food.h"
#include "GameMechs.h"
#include <time.h>
#include <stdlib.h>
#include "objPos.h"

Food::Food(GameMechs &gm, objPosArrayList* playerBody) : gameMechs(gm), playerBodyList(playerBody)
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

void Food::generateFood(objPosArrayList* playerBody)
{

    if (!foodGenerated)
    {
        bool isValid;
        do
        {
            rnx = rand() % (gameMechs.getBoardSizeX()-2)+1;
            rny = rand() % (gameMechs.getBoardSizeY()-2)+1;

            isValid = true;

            for (int k = 0; k<playerBody->getSize();k++)
            {
                objPos bodyPos;
                playerBody->getElement(bodyPos,k);

                if(rnx == bodyPos.x && rny == bodyPos.y)
                {
                    isValid = false;
                    break;
                }
            }
        } while (!isValid);

        foodPos.setObjPos(rnx, rny, 'o');
        foodGenerated = true;
    }
}
    

void Food::getFoodPos(objPos &returnPos)
{
    foodPos.getObjPos(returnPos);
}

