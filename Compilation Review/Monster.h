#ifndef PACKMAN_D_MONSTER_H
#define PACKMAN_D_MONSTER_H
#include "BoardObjectH.h"


class Monster: public BoardObject {

private:
    ObjectColours color;

public:
    Monster(int startX, int startY) : BoardObject(startX, startY) {
        color = RED;
    };

    void touch();
};


#endif //PACKMAN_D_MONSTER_H
