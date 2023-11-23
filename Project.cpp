#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

//bool exitFlag;  --> instructions say to delete all global vars besides the pointer
GameMechs *myGM;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(!myGM->getExitFlagStatus())  
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

    //exitFlag = false;
    myGM = new GameMechs();
}

void GetInput(void)
{
    

}

void RunLogic(void)
{





}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    objPos = tempPos;
    myPlayer.getPlayerPos(tempPos);

    MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(),tempPos.x,tempPos.y,tempPos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGM;
}