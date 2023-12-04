#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"


using namespace std;


char border[30][15];



#define DELAY_CONST 100000

objPos printPos;


GameMechs* myGM;
Player* player;
Food* food;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    myGM = new GameMechs(30,15);
    player = new Player(myGM);
    food = new Food(*myGM); 
    srand(time(NULL));



    

}

void GetInput(void)
{
    char input = myGM->getInput();
}

void RunLogic(void)
{
    char input = myGM->getInput();

    if(input == 27) //exit key
    {
        myGM -> setExitTrue();
    }

    if (input == 'r') // debugging key
    {
        food->resetFood();
    }

    if (input == 't') //debugging key
    {
        myGM->incrementScore();
        MacUILib_printf("score is:%d",myGM->getScore());
    }

    if (input == 'y') //debugging key
    {
        myGM->setLoseFlag();
        MacUILib_printf("better luck next time");
    }


    objPosArrayList* playerPos = player->getPlayerPos();

    player->updatePlayerDir();
    player->movePlayer();



    food->generateFood(*playerPos);



    myGM->clearInput(); 

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    bool drawn;

    objPosArrayList* playerBody = player->getPlayerPos();
    objPos tempBody;
    int i,j;
    objPos playerPos;

    objPos foodPos;
    food->getFoodPos(foodPos);
    
    for (i=0; i<myGM->getBoardSizeY(); i++)
    {
        for (j=0; j< myGM->getBoardSizeX(); j++)
        {
            drawn = false;
            for (int k =0; k<playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody,k);
                if(tempBody.x == j && i == tempBody.y)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }
            if(drawn) continue;

            if (i==0 || i==myGM->getBoardSizeY()-1|| j==0 || j==myGM->getBoardSizeX() -1)
            {
                border[i][j] = '#';
                MacUILib_printf("%c", border[i][j]);
                

            }

            else if (i == foodPos.y && j == foodPos.x)
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            

            else
            {
                border[i][j] = ' ';
                MacUILib_printf("%c", border[i][j] );

            }


        }

        MacUILib_printf("\n");

    }
    MacUILib_printf("BoardSize: %dx%d\n  FoodPos: (%d, %d) Score: %d" ,myGM->getBoardSizeX(), myGM->getBoardSizeY(), foodPos.y, foodPos.x, playerBody->getSize()-1);


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    MacUILib_printf("Game Over, Better Luck Next Time\n");
    MacUILib_printf("Your Score Was: %d", myGM ->getScore());
    MacUILib_uninit();

    delete player;

    delete myGM;

    delete food;


}