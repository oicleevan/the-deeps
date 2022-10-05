/*
    adventure.cpp
    Main file for my text adventure.
    -- oicleevan
*/

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

#include "libeo.h"
#include "startmenu.h"

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

using namespace libeo;

vector<string> enemies = { "Zombie", "Ghost", "Ghoul", "Skeleton", "Demon", "Soldier", "Giant" };

u_char input;
int rand_e;

typedef enum {
    Completed,
    Died,
    Exited
} completions;

short completion_status;

typedef short Health;

class Character
{
    public:
        string  name; // player name
        Health  max_h; // max possible health
        Health  cur_h; // current health

        short   level = 1; // experience level
        int     lvl_amt = 50; // exp required to level up
        int     exp = 0; // current exp
        int     exp_gain = 60; // max exp gain after every victory

        int     max_atk_pwr = 30; // max attack damage

        short   potions = 5; // amount of potion

        short   enemies_defeated = 0; // enemies defeated during game.
};

class Enemy
{
    public:
        string  name; // enemy name

        Health  max_h = 35; // max health
        Health  cur_h = max_h; // current health

        int     atk_dmg = 15; // max attack damage
};

Character   Player;
Enemy       E;

void log_completion()
{
    ofstream logfile;
    logfile.open("LOGS.txt");

    switch(completion_status)
    {
        case Completed:
            logfile << "Congratulations!\n" <<
                        "Your character, " << Player.name << ", defeated leagues of enemies and claimed the treasure!\n" <<
                        "They were level " << Player.level << ", with " << Player.exp << " exp points and a remaining health of " << Player.cur_h << " after defeating all of the enemies!\n" <<
                        "\nI owe you my thanks for playing my game!\no7\n";
            break;
        case Died:
            logfile << "Yikes..\n" << 
                        "Your character, " << Player.name << ", entered the dungeon looking for some enemies to kill and some treasure to find.\n" <<
                        "Unfortunately, the cave dwellers had other plans.\n" <<
                        "After defeating " << Player.enemies_defeated << " enemies, " << Player.name << " died!\n" <<
                        "They were level " << Player.level << ", with " << Player.exp << " exp points.\n" <<
                        "\nI owe you my thanks for playing my game!\no7\n";
            break;
        case Exited:
            logfile << "Your character, " << Player.name << ", entered the dungeon searching for treasure." << endl <<
                        "After defeating " << Player.enemies_defeated << " enemies, they decided they had enough, and quit." << endl <<
                        "They were level " << Player.level << ", with " << Player.exp << " exp points.\n" <<
                        "\nI owe you my thanks for playing my game!\no7\n";
            break;
    }
    logfile.close();
    cout << "> pssst... a hiddle file has been placed somewhere close to this game... it has something special for you!" << endl;
    return;
}

// Different text options differenciated based on what enemy is being confronted
string name_diff(string str)
{
    string out;

    typedef enum { 
        Zombie,
        Ghost,
        Ghoul,
        Skeleton,
        Demon,
        Soldier,
        Giant
    } types;

    switch(rand_e)
    {
        case Zombie:
            out = "\"Brains... brains...\" \n    Yeah... it's a zombie...";
            break;
        case Ghost:
            out = "A ghost appears from thin air, screeching and howling!";
            break;
        case Ghoul:
            out = "A ghoul slurks through the halls...";
            break;
        case Skeleton:
            out = "An inconspicuous pair of bones turns into an skeleton!";
            break;
        case Demon:
            out = "A demon approaches, with an evil look on its face...";
            break;
        case Soldier:
            out = "An evil looking soldier unsheathes his sword!";
            break;
        case Giant:
            out = "A giant stands in your way, holding a large wooden club.";
            break;
        default:
            cout << "You should probably look at this one, chief!\n";
            exit(EXIT_FAILURE);
    }
    return out;
}

string present_info(string name, int health, int level, int exp, int enemies_defeated)
{
    ostringstream oss;
    oss << "Your info:" << endl <<
        "    Name: " << name << endl <<
        "    Level: " << level << endl <<
        "    Exp: " << exp << endl <<
        "    Health: " << health << endl << 
        "    Enemies defeated: " << enemies_defeated << endl;

    string out = oss.str();
    return out;
}

bool is_integer(const string s) { 
    return regex_match(s, regex("[(-|+)|][0-9]+")); 
} 

void battle(string e_name)
{
    E.name = e_name;

    cout << name_diff(E.name) << endl;

    new_line();

    while (E.cur_h > 0)
    {
        ATTACK:
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // clear cin buffer
        cin.clear();

        cout << "Your health: " << Player.cur_h << endl <<
        E.name << "'s health: " << E.cur_h << endl << endl;

        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;

        cout << "What will you do?" << endl <<
        "    1. Attack" << endl <<
        "    2. Run" << endl <<
        "    3. Use potion (" << Player.potions << " available)" << endl;

        cin >> input;

        clrscr();

        switch (input)
        {
            case '1': default:
            {
                int atk_pwr = gen_rand(Player.max_atk_pwr);
                E.cur_h -= atk_pwr;

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
                if(Player.cur_h + 50 >= Player.max_h)
                {
                    Player.cur_h += 50;
                } else {
                    Player.cur_h = Player.max_h;
                }

                Player.potions--;
                cout << "You used a potion and now have " << Player.cur_h << " health." << endl <<
                "You have " << Player.potions << " potions left.\n" << endl;
              } else {
                cout << "You are out of potions! You cannot use any more.\n" << endl;
                goto ATTACK;
              }
                break;
        }

        if(E.cur_h >= 1)
        {
            int enemy_atk = gen_rand(E.atk_dmg);

            if(enemy_atk >= 1) {
                Player.cur_h -= enemy_atk;
                cout << "The " << E.name << " attacked you for " << enemy_atk << " damage!\n" << endl;
            } else {
                cout << "The " << E.name << " tried to attack you,\n    but missed!";
            }
        }

        if(Player.cur_h <= 0) break;
    }

    if(Player.cur_h <= 0) {
        cout << "You collapsed...";
        sleep_for(milliseconds(1500));
        cout << "you died!" << endl;
        completion_status = Died;

        sleep_for(milliseconds(2500));

        cout << "Thanks for playing!" << endl;

        log_completion();
        exit(EXIT_SUCCESS);

    }

    cout << "The " << E.name << " died." << endl;
    Player.enemies_defeated++;

    new_line();

    // give player exp
    int exp_gained = gen_rand(Player.exp_gain);
    Player.exp += exp_gained;

    cout << "You gained " << exp_gained << " experience points. You now have " << Player.exp << " exp." << endl;

    if(Player.exp >= Player.lvl_amt)
    {
        Player.level++;
        Player.max_atk_pwr += 10;
        Player.max_h += 5;
        Player.cur_h += 5;
        Player.exp -= 50;
        cout << "\nYou have leveled up!" << endl <<
        "You are now level " << Player.level << ", with " << Player.exp << " experience points." << endl;
    }

    // give potion if warranted
    int chance_of_potion = gen_rand(3);
    if(chance_of_potion == 3)
    {
        Player.potions++;
        cout << "\nYou found a potion on the body of the " << E.name << "." << endl;
    }

    // make enemy more difficult
    E.max_h += 5;
    E.atk_dmg += 5;
    E.cur_h = E.max_h;

    return;
}

int main(int argc, char *argv[])
{
    if(start_menu() != true) {
        cout << "Ok... exiting..." << endl;
        exit(EXIT_SUCCESS);
    }

    if (argc > 1) {
        if(is_integer(argv[1]))
        {
            int p_health = stoi(argv[1]);
            Player.cur_h = p_health;
        } else {
            Player.cur_h = 50;
        }
    } else {
        Player.cur_h = 50;
    } 
    Player.max_h = Player.cur_h;

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

        rand_e = gen_rand(enemies.size());
        battle(enemies[rand_e]);

        if(Player.enemies_defeated == 8)
        {
            cout << R"(                         ____                            _         _       _   _                 _ 
                        / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___| |
                        | |   / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __| |
                        | |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \_|
                        \____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___(_)
                                        |___/                                                     )" << endl;

            cout << "With the last enemy defeated, you have found your way to the treasure!" << endl;
            cout << "Congratulations for completing the game!" << endl;

            completion_status = Completed;
            sleep_for(milliseconds(3000));
            break;
        }

        input = NULL;
        while(input != '1' && input != '3') {

            cout << "\nWhat is next? Do you:" << endl <<
                "    1. Continue deeper into the dungeon" << endl <<
                "    2. Check your info" << endl << 
                "    3. Exit" << endl;

            cin >> input;

            new_line();

            switch (input)
            {
                case '1':
                    cout << "You decide to continue deeper into the dungeon..." << endl;
                    break;
                case '2':
                    clrscr();
                    cout << present_info(Player.name, Player.cur_h, Player.level, Player.exp, Player.enemies_defeated);
                    break;
                case '3':
                    cout << "You exit the dungeon, leaving your sword behind..." << endl;
                    sleep_for(milliseconds(3000));
                    is_playing = false;
                    completion_status = Exited;
                    break;
                default:
                    cout << "Please specify one of the specified options!" << endl;
            }
        }
    }

    log_completion();
    sleep_for(milliseconds(3000));
    cout << "\nThanks for playing!" << endl;

    return 0;
}
