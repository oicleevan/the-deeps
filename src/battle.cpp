#include <iostream>

#include "adventure.h"

void battle(Character p, std::string e_name, int e_health, int e_atk_dmg)
{
    Enemy Enemy;
    Enemy.name = e_name;
    Enemy.health = e_health;
    Enemy.atk_dmg = e_atk_dmg;

    std::cout << p.name << ", you are going to fight a " << Enemy.name << "." << std::endl;
}