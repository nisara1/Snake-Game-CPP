#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    int intialX = mainGameMechsRef->getBoardSizeX()/2;
    int intialY = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.setObjPos(intialX, intialY, '*');
}

Player::~Player()
{
// leave it empty for now
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
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
                if(myDir != RIGHT)
                {
                    myDir = LEFT;

                }
                break;
            case 's':
                if(myDir != UP)
                {
                    myDir = DOWN;

                }
                break;
            case 'd':
                if(myDir != LEFT)
                {
                    myDir = RIGHT;

                }
            default:
                break;
        }
        

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    switch(myDir)
    {
        case STOP:
            break;
        case UP:
            playerPos.y--;
            break;
        case DOWN:
            playerPos.y++;
            break;
        case LEFT:
            playerPos.x--;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        
        default:
            break;     

    }


}

