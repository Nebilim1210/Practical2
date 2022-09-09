#include <iostream>

#include "BoardH.h"

using namespace std;

void banner()
{
	cout << "***************************************************" << endl;
	cout << "*                                                 *" << endl;
	cout << "*  Welcome to TEXT-BASED PACKMAN		   *" << endl;
	cout << "*                                                 *" << endl;
	cout << "*  (c) 2010  Vlad Estivill_Castro		   *" << endl;
	cout << "*                                                 *" << endl;
	cout << "*   E<cr> - Move up		                   *" << endl;
	cout << "*   X<cr> - Move down 	                           *" << endl;
	cout << "*   S<cr> - Move left 	                           *" << endl;
	cout << "*   D<cr> - Move right 	                   *" << endl;
	cout << "*   P<cr> - Park   	                           *" << endl;
	cout << "*                                                 *" << endl;
	cout << "***************************************************" << endl;


}

int main()

{
    //Testing of our new classes : Monster and Bomb

    Monster monster = Monster(0,0);
    Bomb bomb = Bomb(1,1);

    //We should get a message on stdout if those methods are working.
    monster.touch();
    bomb.touch();

    //now let's create instances of other board objects.
    Cookie cookie = Cookie(2,2);
    Player player = Player(3,3);
    Wall wall = Wall(1,2);

    //And we test our vector capabilities to store these objects.
    VectorBoardObjects vectorBoardObjects = VectorBoardObjects(&player);
    vectorBoardObjects.addOne(&monster);
    vectorBoardObjects.addOne(&bomb);
    vectorBoardObjects.addOne(&cookie);

    //The last one should give an error, since a vector capacity is limited to 4 objects.
    //vectorBoardObjects.addOne(&wall);

    //Now let's test the other methods
    //This should print the value of cookies
    std::cout << vectorBoardObjects.isCookieValue() << endl;
    //This should print false since there is no wall in the vector.
    std::cout << vectorBoardObjects.isThereAWall() << endl;

    //finally we test our removeOnePlayer, and TheNext methods by using the first one then iterating through the vector using the second and third one.
    vectorBoardObjects.removeOnePlayer();
    p_BoardObject object = vectorBoardObjects.theFirst();

    int countvector = 0;

    while (object != NULL)
    {
        countvector+= 1;
        object->touch();
        object = vectorBoardObjects.theNext();
    }

    //Now let's count the number of objects in our vector. We ate a cookie by getting its value, and we removed one player so it should be displaying 2.
    std::cout << "number of elements : " << countvector << endl;

	char aMove;
	banner();

	// Initialize

	Board theBoard (7,7);

	// Set Up

        do{


	theBoard.paint();

	cin >> aMove;	

	if ( ('E'==aMove) || ('X'==aMove) || ('S'==aMove) || ('D'==aMove) )
		 aMove=aMove-'A'+'a';

	if ( ! (
           ('e'==aMove) || ('x'==aMove) || ('s'==aMove) || ('d'==aMove) 
            ) ) aMove='p';

	theBoard.move(aMove);

	} while (theBoard.IamAlive());


        return 0;
}

