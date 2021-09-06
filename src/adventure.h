#ifndef ADVENTURE_H
#define ADVENTURE_H

#include <iostream>

class Character
{
    public:
        std::string name;
        int health;
        int exp_level = 1;
        int exp = 0;
};

class Enemy
{
    public:
        std::string name;
        int health;
        int atk_dmg;
};

void battle(Character p, std::string e_name, int e_health, int e_atk_dmg);

#endif