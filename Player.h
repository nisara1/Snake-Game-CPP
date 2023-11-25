#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption();
        void increasePlayerLength();

        // Need more actions
        // after inserting head and before removing tail
        // -check if new head position collides with food
        // - if yes increment the score if GM and genertate new food and  do not remove tial
        //- otherwise remove tail and move on


        //Lastly add self collision check
        // if self collided set loosFelag anf exit flag to true (through GM)
        //this will break program loop and end game

        //- if ending, you need to differentiate the end game state
        // LOST - display lost message
        // otherwise, display ENDGAME messgage only


    private:
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif