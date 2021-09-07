#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;
using std::this_thread::sleep_for;

void clrscr()
{
    cout << "\033[2J\033[1;1H";
    return;
}

vector<string> enemies = {"Zombie", "Ghost", "Ghoul", "Skeleton", "Gravekeeper"};
signed char input;
int rand_enemy;

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

void battle(string e_name)
{
    srand(time(0));

    E.name = e_name;

    cout << "A " << E.name << " approaches!\n" << endl;

    while (E.health > 0)
    {
        cout << "Your health: " << Player.health << endl <<
        E.name << "'s health: " << E.health << endl << endl;

        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;

        cout << "What will you do?" << endl <<
        "    1. Attack" << endl <<
        "    2. Run" << endl <<
        "    3. Use potion (" << Player.potions << " available)" << endl;

        cin >> input;

        printf("\n");

        switch (input) 
        {
            case '1': default:
            {
                int atk_pwr = rand() % Player.max_atk_pwr + 1;
                
                E.health -= atk_pwr;

                cout << "You attacked the " << E.name << " for " << atk_pwr << " damage." << endl;

                break;
            }
            case '2':
                if(rand() % 4 == 1)
                {
                    cout << "You successfully ran away." << endl;
                    return;
                } else {
                    cout << "You tried to run away, but failed!" << endl;
                }
                
                break;
            case '3':
                Player.health = Player.max_health;
                Player.potions--;
                cout << "You used a potion and now have " << Player.health << " health." << endl <<
                "You have " << Player.potions << " potions left.\n" << endl;

                break;
        }

        if(E.health >= 1)
        {
            int enemy_atk = rand() % E.atk_dmg + 1;
            Player.health -= enemy_atk;

            cout << "The " << E.name << " attacked you for " << enemy_atk << " damage!\n" << endl;
        }

        if(Player.health <= 0) break;
    }

    if(Player.health <= 0) {
        cout << "You collapsed...";
        sleep_for(1500ms);
        cout << "you died!" << endl;

        sleep_for(2500ms);

        cout << "Thanks for playing!" << endl;
        exit(EXIT_SUCCESS);

    }

    cout << "The " << E.name << " died." << endl;
    Player.enemies_defeated++;

    // give player exp

    int exp_gained = rand() % Player.exp_gain + 1;
    Player.exp += exp_gained;

    cout << "You gained " << exp_gained << " experience points. You now have " << Player.exp << " exp." << endl;

    if(Player.exp >= Player.lvl_amt)
    {
        Player.level++;
        Player.exp -= 50;
        cout << "\nYou have leveled up!" << endl <<
        "You are now level " << Player.level << ", with " << Player.exp << " experience points." << endl;
    }

    // return potion potential

    int chance_of_potion = rand() % 3 + 1;
    if(chance_of_potion == 3)
    {
        Player.potions++;
        cout << "You found a potion on the body of the " << E.name << "." << endl;
    }

    // make enemy more difficult

    E.max_health += 5;
    E.health = E.max_health;
    E.atk_dmg += 5;

    return;
}

int main()
{
    clrscr();

    cout << "Text based adventure by oicleevan" << endl;

    sleep_for(3000ms);

    Player.health = 50;
    Player.max_health = Player.health;

    cout << "\nWhat is your name?: ";
    cin >> Player.name;

    cout << "\nHello, " << Player.name << ". You are now venturing into a dungeon, against forces who are ready to fight you... " << endl;

    while (true)
    {
        sleep_for(2500ms);
        clrscr();

        srand(time(0));
        rand_enemy = rand() % enemies.size() + 1;

        battle(enemies[1]);

        if(Player.enemies_defeated == 7)
        {
            cout << "With the last enemy defeated, you have found your way to the treasure!" << endl;
            cout << "Congratulations for completing the game!" << endl;

            sleep_for(3000ms);
            break;
        }

        cout << "\nWhat is next? Do you:" << endl <<
        "    1. Continue deeper into the dungeon" << endl <<
        "    2. Exit" << endl;

        cin >> input;

        printf("\n");

        if(input == '1')
        {
            cout << "You decide to continue deeper into the dungeon..." << endl;
        } else if(input == '2') {
            cout << "You exit the dungeon, leaving your sword behind..." << endl;

            sleep_for(3000ms);
            break;
        }
    }

    cout << "\n Thanks for playing!" << endl;

    return 0;
}
