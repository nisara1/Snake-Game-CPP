#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"
#include "time.h"
#include "Food.h"
#include "objPos.h"
#include "GameMechs.h"

extern Food* food;

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,  mainGameMechsRef->getBoardSizeY()/2, '*'); //simpler way can be written

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);


    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);



}

Player::~Player()
{
// leave it empty for now
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 
    char input = mainGameMechsRef->getInput();

    switch(input)
        {                      
            case 'w':
                if(myDir != DOWN)
                {
                    myDir = UP;

                }
                break;
            case 'a':
                if(  myDir!= RIGHT)
                {
                    myDir = LEFT;

                }
                break;
            case 's':
                if(  myDir != UP)
                {
                    myDir = DOWN;

                }
                break;
            case 'd':
                if(  myDir != LEFT)
                {
                    myDir = RIGHT;

                }
                break;
            default:
                break;
        }
    mainGameMechsRef->clearInput();

}

bool Player::checkFoodConsumption()
{
    objPos headpos;
    playerPosList->getHeadElement(headpos);

    objPos foodPos;
    food->getFoodPos(foodPos);

    if(headpos.x==foodPos.x && headpos.y==foodPos.y)
    {
        return true;
    }

    return false;
}

void Player::increasePlayerLength()
{
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    playerPosList->insertHead(currHead);
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos newHead;
    objPos currHead;
    playerPosList->getHeadElement(currHead);

    switch(myDir)
    {
        case STOP:
            break;
        case UP:
            currHead.y--;
            if(currHead.y <= 0)
                currHead.y = mainGameMechsRef->getBoardSizeY() -2;
            break;
        case DOWN:
            currHead.y++;
            if(currHead.y >= mainGameMechsRef->getBoardSizeY()-1)
                currHead.y = 1;
            break;
        case LEFT:
            currHead.x--;
            if(currHead.x <= 0)
                currHead.x = mainGameMechsRef->getBoardSizeX() -2;
            break;
        case RIGHT:
            currHead.x++;
            if(currHead.x >= mainGameMechsRef->getBoardSizeX()-1)
                currHead.x = 1;
            break;
        
        default:
            break;     
    }

    playerPosList->insertHead(currHead);

    if(checkFoodConsumption())
    {
        increasePlayerLength();

        food->generateFood(currHead);
        food->resetFood();
    }
    else
    {
        playerPosList->removeTail();
    }

}

