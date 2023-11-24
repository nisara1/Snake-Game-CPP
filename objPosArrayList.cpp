#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;

}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;

}

int objPosArrayList::getSize()
{
    return listSize;

}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize < arrayCapacity)
    {
        for(int i= listSize; i>0; i-- )
        {
            aList[i].setObjPos(aList[i-1]);

        }
        aList[0].setObjPos(thisPos);

        listSize++;
    }


}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize < arrayCapacity)
    {
        aList[listSize].setObjPos(thisPos);
        listSize++;
    }
    //condition for capacity

}

void objPosArrayList::removeHead()
{
    if(listSize > 0)
    {
        for(int i = 0; i<listSize -1; i++)
        {
            aList[i].setObjPos(aList[i+1]);
        }
        listSize--;
    }
    //need condition for empty array cannot remove then
    
}

void objPosArrayList::removeTail()
{
    if(listSize > 0)
    {
        listSize--;
    }
    else
    {


    }

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);

}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);

}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);

}
