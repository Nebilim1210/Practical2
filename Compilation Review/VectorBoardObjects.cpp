#include <iostream>
#include "BoardObjectH.h"
#include "VectorBoardObjects.h"

//To create the class VectorBoardObjects we reuse a lot of the ListBoardObjects methods while readapting them.
//Most of them will simply have renamed variables for readability, but VectorBoardObjects will need a precondition.
VectorBoardObjects:: VectorBoardObjects(p_BoardObject newOne):vector()
{
    std::vector <p_BoardObject>:: iterator it;
    it=vector.begin();
    vector.insert(it,newOne);
}

p_BoardObject VectorBoardObjects:: theFirst()
{
    if (0 < vector.size())
    { internalIterator=vector.begin();
        return (*internalIterator);
    }
    else
        return NULL;
}

//We take the same method for adding objects, but we add a condition to limit the number of objects in the vector.
void VectorBoardObjects:: addOne(p_BoardObject newOne)
{
    if (vector.size() < 4) {
        std::vector<p_BoardObject>::iterator it;
        it = vector.begin();
        vector.insert(it, newOne);
    } else //There are already 4 objects in our vector.
    {
        std::cerr << "Tried to add new object in VectorBoardObjects but maximum of objects in vector is 4." << std::endl;
        //throw std::invalid_argument( "Tried to add new object in VectorBoardObjects but maximum of objects in vector is 4." );
    }
}

//This method is taken from ListBoardObjects
p_BoardObject VectorBoardObjects :: theNext()
{
    internalIterator++;
    if (internalIterator < vector.end())
    {
        return (*internalIterator);
    }
    else
        return NULL;
}

//This method is taken from ListBoardObjects
void VectorBoardObjects :: removeOnePlayer()
{
    std::vector <p_BoardObject>:: iterator it;
    it=vector.begin();
    while (it<vector.end())
    { if (A_PLAYER==(*it)->get_Type())
        { vector.erase(it); return;}
        it++;
    }

    return ;
}

//This method is taken from ListBoardObjects
bool VectorBoardObjects :: isThereAWall()
{
    std::vector <p_BoardObject>:: iterator it;
    it=vector.begin();
    while (it<vector.end())
    { if (A_WALL==(*it)->get_Type())
        {  return true;}
        it++;
    }

    return false ;
}

//This method is taken from ListBoardObjects
int VectorBoardObjects :: isCookieValue()
{   int temp=0;
    std::vector <p_BoardObject>:: iterator it;
    it=vector.begin();
    while (it<vector.end())
    { if (A_COOKIE==(*it)->get_Type())
        { temp= ((Cookie *)(*it))->get_value();
            vector.erase(it);
            return temp;
        }
        it++;
    }

    return temp ;
}
