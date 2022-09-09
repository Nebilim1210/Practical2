#include <iostream>
#include "BoardObjectH.h"
#include "ListBoardObjectsH.h"

//! Constructor of a ListBoardObjects. this list can't be empty so an argument to choose the first element is necessary.
ListBoardObjects:: ListBoardObjects(p_BoardObject newOne):list()
	{
	 	std::vector <p_BoardObject>:: iterator it;
	 	it=list.begin();
	 	list.insert(it,newOne);
        }
//! Gets the first element of our list
p_BoardObject ListBoardObjects:: theFirst()
	{
	   if (0 < list.size()  )
		{ internalIterator=list.begin();
	   	  return (*internalIterator);
		}
	   else
		return NULL;
	}

//! Adds one object set as parameter in our list
void ListBoardObjects:: addOne(p_BoardObject newOne)
	 { 
	 	std::vector <p_BoardObject>:: iterator it;
	 	it=list.begin();
	 	list.insert(it,newOne);
	 }
//! After theFirst has been called, theNext works as an iterator pointing to every object of the list in order starting from the second one. Returns NULL when arrived at the end of the list.
p_BoardObject ListBoardObjects :: theNext()
	{
	   internalIterator++;
	   if (internalIterator < list.end())
	   {
		   return (*internalIterator);
	   }
	   else
		return NULL;
	}
//! Removes a player object from the list
void ListBoardObjects :: removeOnePlayer()
	{
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_PLAYER==(*it)->get_Type())
		   { list.erase(it); return;}
                  it++;
		}

	   return ;
	}

//! returns true if a wall object is present in the list.
bool ListBoardObjects :: isThereAWall()
	{
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_WALL==(*it)->get_Type())
		   {  return true;}
                  it++;
		}

	   return false ;
	}

//! Returns the value of a cookie if one is present in the list. If that's the case, remove the first cookie encountered.
int ListBoardObjects :: isCookieValue()
	{   int temp=0;
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_COOKIE==(*it)->get_Type())
		   { temp= ((Cookie *)(*it))->get_value();
		     list.erase(it); 
		     return temp;
                   }
                  it++;
		}

	   return temp ;
	}
