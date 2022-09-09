#include <iostream>
#include "Monster.h"
//! Defines what happens when a player touches the object
void Monster :: touch()
{
    std::cout << "You touched a monster." << std::endl;
};