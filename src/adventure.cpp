#include <iostream>

#include "adventure.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Text based adventure by oicleevan" << endl;

    while (true)
    {
        Character Player;
        Player.health = 50;

        cout << "What is your name?: ";
        cin >> Player.name;

        cout << "Your name is " << Player.name << endl;
        cout << "Your health is " << Player.health << endl;
        cout << "Your exp level is " << Player.exp_level << " with " << Player.exp << " exp points" << endl;

        battle(Player, "Zombie", 22, 8);
    }

    return 0;
}