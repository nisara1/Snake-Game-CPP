#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos(); //player position is called upoon from player class which is then used by the objPosArrayList
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption();
        void increasePlayerLength();
        bool checkSelfCollision(const objPos& headPos);



    private:
        objPosArrayList *playerPosList;     
        enum Dir myDir;

        GameMechs* mainGameMechsRef;
};

#endif