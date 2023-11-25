#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"


using namespace std;

#define r 15
#define coln 30

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

    if(input == 27)
    {
        myGM -> setExitTrue();
    }

    if (input == 'r') 
    {
        food->resetFood();
    }

    if (input == 't')
    {
        myGM->incrementScore();
        MacUILib_printf("score is:%d",myGM->getScore());
    }

    if (input == 'y')
    {
        myGM->setLoseFlag();
        MacUILib_printf("better luck next time");
    }



    player->updatePlayerDir();
    player->movePlayer();


    objPosArrayList* playerBodyList;
    player->getPlayerPos(playerBodyList);  
    food->generateFood(playerBodyList);


    myGM->clearInput(); 

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPos tempPos;
    player->getPlayerPos(tempPos);
    int i,j;
    objPos playerPos;
    player->getPlayerPos(playerPos);

    objPos foodPos;
    food->getFoodPos(foodPos);
    
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
    MacUILib_printf("BoardSize: %dx%d\n, Player at (%d, %d): %c\n, Score: %d\n",myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol, myGM->getScore());


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    delete player;
    delete food;
    delete myGM;
    MacUILib_clearScreen();    
  
    MacUILib_uninit();


}