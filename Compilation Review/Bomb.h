#ifndef PACKMAN_D_BOMB_H
#define PACKMAN_D_BOMB_H
#include "BoardObjectH.h"


class Bomb: public BoardObject {

private:
    ObjectColours color;

public:
    Bomb(int startX, int startY) : BoardObject(startX, startY) {
        color = BLACK;
    }

    void touch();

};


#endif //PACKMAN_D_BOMB_H
