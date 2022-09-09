#include <vector>
#include  "BoardObjectH.h"
#include  "PlayerH.h"
#include  "CookieH.h"
#ifndef PACKMAN_D_VECTORBOARDOBJECTS_H
#define PACKMAN_D_VECTORBOARDOBJECTS_H
typedef BoardObject* p_BoardObject;


class VectorBoardObjects {

    std::vector <p_BoardObject> vector;
    std::vector < p_BoardObject>::iterator internalIterator;
public:
    VectorBoardObjects(p_BoardObject theFirst);

    p_BoardObject theFirst();
    p_BoardObject theNext();
    void addOne(p_BoardObject newOne);
    void removeOnePlayer();
    bool isThereAWall();
    int isCookieValue();
};
#endif