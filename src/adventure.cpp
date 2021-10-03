/*
    adventure.cpp
    Main file for my text adventure.
    -- oicleevan
    
    current release: 2.1
*/

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>

#include "libeo.h"
#include "startmenu.h"

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

using namespace libeo;

vector<string> enemies = { "Zombie", "Ghost", "Ghoul", "Skeleton", "Demon", "Corrupt Knight" };

unsigned char input;
bool has_completed = false;

class Character
{
    public:
        string name; // player name
        int max_health; // max possible health
        int health; // current health
        int level = 1; // experience level
        int lvl_amt = 50; // exp required to level up
        int exp = 0; // current exp
        int exp_gain = 60; // max exp gain after every victory

        int max_atk_pwr = 30; // max attack damage

        int potions = 5;

        int enemies_defeated = 0;
};

class Enemy
{
    public:
        string name; // enemy name

        int max_health = 35; // max health
        int health = max_health; // current health

        int atk_dmg = 15; // max attack damage
};

Character Player;
Enemy E;

void log_completion()
{
    ofstream logfile;
    logfile.open("LOGS.txt");

    if(has_completed)
    {
        logfile << "Congratulations!\n" <<
                    "Your character, " << Player.name << ", defeated leagues of enemies and claimed the treasure!\n" <<
                    "They were level " << Player.level << ", with " << Player.exp << " exp points and a remaining health of " << Player.health << " after defeating all of the enemies!\n" <<
                    "\nI owe you my thanks for playing my game!\no7\n";
    } else {
        logfile << "Yikes..\n" << 
                    "Your character, " << Player.name << ", entered the dungeon looking for some enemies to kill and some treasure to find.\n" <<
                    "Unfortunately, the cave dwellers had other plans.\n" <<
                    "After defeating " << Player.enemies_defeated << " enemies, " << Player.name << " died!\n" <<
                    "They were level " << Player.level << ", with " << Player.exp << " exp points.\n" <<
                    "\nI owe you my thanks for playing my game!\no7\n";
    }
    
    logfile.close();
    cout << "> pssst... a hiddle file has been placed somewhere close to this game... it has something special for you!" << endl;

    return;
}

// Different text options differenciated based on what enemy is being confronted
string name_diff(string str)
{
    string out;

    if(str.compare("Zombie") == 0) {
        out = "\"Brains... brains...\" \n    Yeah... it's a zombie...";
    } else if(str.compare("Ghost") == 0) {
        out = "A ghost appears from thin air, screeching and howling!";
    } else if(str.compare("Ghoul") == 0) {
        out = "A ghoul slurks through the halls...";
    } else if(str.compare("Skeleton") == 0) {
        out = "An inconspicuous pair of bones turns into an skeleton!";
    } else if(str.compare("Demon") == 0) {
        out = "A demon approaches, with an evil look on its face...";
    } else if(str.compare("Corrupt Knight") == 0) {
        out = "An evil looking knight unsheathes his sword!";
    } else {
        cout << "You should probably look at this one, chief!\n"; exit(EXIT_FAILURE); // ERROR MESSAGE!!!!
    }

    return out;
}

void present_info(string name, int health, int level, int exp, int enemies_defeated)
{
    cout << "> Your info: " << endl 
        << "    Name: " << name << endl
        << "    Level: " << level << endl
        << "    EXP Points: " << exp << endl
        << "    Health: " << health << endl
        << "    Enemies defeated: " << enemies_defeated << endl;

    return;
}

void battle(string e_name)
{
    E.name = e_name;

    cout << name_diff(E.name) << endl;

    new_line();

    while (E.health > 0)
    {
        ATTACK:
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // clear c++ buffer

        cout << "Your health: " << Player.health << endl <<
        E.name << "'s health: " << E.health << endl << endl;

        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;

        cout << "What will you do?" << endl <<
        "    1. Attack" << endl <<
        "    2. Run" << endl <<
        "    3. Use potion (" << Player.potions << " available)" << endl;

        cin >> input;

        new_line();

        switch (input)
        {
            case '1': default:
            {
                int atk_pwr = gen_rand(Player.max_atk_pwr);
                E.health -= atk_pwr;

                cout << "You attacked the " << E.name << " for " << atk_pwr << " damage." << endl;

                break;
            }
            case '2':
                if(gen_rand(4) == 1)
                {
                    cout << "You successfully ran away." << endl;
                    return;
                } else {
                    cout << "You tried to run away, but failed!" << endl;
                }
                break;
            case '3':
              if(Player.potions > 0) {
                if(Player.health + 50 >= Player.max_health)
                {
                    Player.health += 50;
                } else {
                    Player.health = Player.max_health;
                }

                Player.potions--;
                cout << "You used a potion and now have " << Player.health << " health." << endl <<
                "You have " << Player.potions << " potions left.\n" << endl;
              } else {
                cout << "You are out of potions! You cannot use any more.\n" << endl;
                goto ATTACK;
              }
                break;
        }

        if(E.health >= 1)
        {
            int enemy_atk = gen_rand(E.atk_dmg);
            Player.health -= enemy_atk;

            cout << "The " << E.name << " attacked you for " << enemy_atk << " damage!\n" << endl;
        }

        if(Player.health <= 0) break;
    }

    if(Player.health <= 0) {
        cout << "You collapsed...";
        sleep_for(milliseconds(1500));
        cout << "you died!" << endl;

        sleep_for(milliseconds(2500));

        cout << "Thanks for playing!" << endl;

        log_completion();
        exit(EXIT_SUCCESS);

    }

    cout << "The " << E.name << " died." << endl;
    Player.enemies_defeated++;

    // give player exp
    int exp_gained = gen_rand(Player.exp_gain);
    Player.exp += exp_gained;

    cout << "You gained " << exp_gained << " experience points. You now have " << Player.exp << " exp." << endl;

    if(Player.exp >= Player.lvl_amt)
    {
        Player.level++;
        Player.max_atk_pwr += 10;
        Player.max_health += 5;
        Player.health += 5;
        Player.exp -= 50;
        cout << "\nYou have leveled up!" << endl <<
        "You are now level " << Player.level << ", with " << Player.exp << " experience points." << endl;
    }

    // return potion potential
    int chance_of_potion = gen_rand(3);
    if(chance_of_potion == 3)
    {
        Player.potions++;
        cout << "\nYou found a potion on the body of the " << E.name << "." << endl;
    }

    // make enemy more difficult
    E.max_health += 5;
    E.health = E.max_health;
    E.atk_dmg += 5;

    return;
}

int main()
{
    if(start_menu() != true) {
        cout << "Ok... exiting..." << endl;
        exit(EXIT_SUCCESS);
    }

    Player.health = 50;
    Player.max_health = Player.health;

    cout << "\nWhat is your name?: ";
    cin >> Player.name;

    cout << "Hello, " << Player.name << ". You are now venturing into a dungeon, against forces who are ready to fight you... " << endl;

    clrscr();
    srand(time(0));

    bool is_playing = true;
    while (is_playing)
    {
        sleep_for(chrono::milliseconds(2500));
        clrscr();

        int rand_enemy = gen_rand(enemies.size());

        battle(enemies[rand_enemy]);

        if(Player.enemies_defeated == 8)
        {
            //MacOS does not support raw processing of text.
            #ifdef __linux__
                cout << R"(                         ____                            _         _       _   _                 _ 
                            / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___| |
                            | |   / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __| |
                            | |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \_|
                            \____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___(_)
                                            |___/                                                     )";
            #elif __APPLE__
                cout << "Congratulations!";
            #else
                cout < "This os is not supported!";
                exit(EXIT_FAILURE);
            #endif

            cout << endl;
            cout << "With the last enemy defeated, you have found your way to the treasure!" << endl;
            cout << "Congratulations for completing the game!" << endl;

            has_completed = true;
            sleep_for(milliseconds(3000));
            break;
        }

        SELECTION:
        cout << "\nWhat is next? Do you:" << endl <<
            "    1. Continue deeper into the dungeon" << endl <<
            "    2. Check your info" << endl << 
            "    3. Exit" << endl;

        cin >> input;

        new_line();

        switch (input)
        {
            case '1': default:
                cout << "You decide to continue deeper into the dungeon..." << endl;
                break;
            case '2':
                present_info(Player.name, Player.health, Player.level, Player.exp, Player.enemies_defeated);
                goto SELECTION;
            case '3':
                cout << "You exit the dungeon, leaving your sword behind..." << endl;
                sleep_for(milliseconds(3000));
                is_playing = false;
                break;
        }
    }

    log_completion();

    sleep_for(milliseconds(3000));

    cout << "\nThanks for playing!" << endl;

    return 0;
}
