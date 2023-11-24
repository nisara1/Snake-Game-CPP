#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;

#define r 15
#define coln 30

char border[30][15];



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
    myGM = new GameMechs(30,15);
    player = new Player(myGM);

}

void GetInput(void)
{
    char input = myGM->getInput();
    if(input == 27)
    {
        myGM -> setExitTrue();
    }
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();

    char input = myGM->getInput();

    if (input == 't')
    {
        myGM->incrementScore();
        MacUILib_printf("Score incremented: %d ", myGM->getScore());
    }

    if (input == 'y')
    {
        myGM->setLoseFlag();
        MacUILib_printf("Lose flag set. Game over.");
    }

    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPos tempPos;
    player->getPlayerPos(tempPos);
    MacUILib_printf("BoardSize: %dx%d Player at (%d, %d): %c\n",myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol);

    int i,j;
    for (i=0; i<r; i++)
    {
        for (j=0; j<coln; j++)
        {
            if (i==0 || i==r-1|| j==0 || j==coln -1)
            {
                border[i][j] = '#';
                MacUILib_printf("%c", border[i][j]);
                

            }
            else if(i == tempPos.y && j== tempPos.x)
            {
                MacUILib_printf("%c", tempPos.symbol);
                    
            }
            

            else
            {
                border[i][j] = ' ';
                MacUILib_printf("%c", border[i][j] );

            }

        }

        MacUILib_printf("\n");
       

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