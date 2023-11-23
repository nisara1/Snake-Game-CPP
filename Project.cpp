#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;

#define rows 30
#define columns 15

#define DELAY_CONST 100000

objPos printPos;


GameMechs* myGM;
Player* player;

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
    myGM = new GameMechs(26,13);
    player = new Player(myGM);

}

void GetInput(void)
{

   
}

void RunLogic(void)
{
    player->updatePlayerDir();

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPos tempPos;
    player->getPlayerPos(tempPos);
    MacUILib_printf("BoardSize: %dx%d Player at (%d, %d): %c\n",myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol);


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1)
            {
                MacUILib_printf("#");
            }

            else
            {
                MacUILib_printf(" ");
            }
        }
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete player;

    delete myGM;

}