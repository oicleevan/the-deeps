/*
    startmenu.cpp
    menu system for the deeps
    -- oicleevan
*/

#include <iostream>
#include <thread>
#include <chrono>

#include "libeo.h"
#include "startmenu.h"

using std::cout;
using std::cin;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

using namespace libeo;

void title_screen()
{
    clrscr();

    //MacOS does not support raw processing of text.
    #ifdef __linux__
        //Sets terminal size to 32 lines, 118 columns.
        cout << "\e[8;32;118t";
        cout << R"(                  ___           ___                   _____          ___           ___           ___         ___     
      ___        /__/\         /  /\                 /  /::\        /  /\         /  /\         /  /\       /  /\    
     /  /\       \  \:\       /  /:/_               /  /:/\:\      /  /:/_       /  /:/_       /  /::\     /  /:/_   
    /  /:/        \__\:\     /  /:/ /\             /  /:/  \:\    /  /:/ /\     /  /:/ /\     /  /:/\:\   /  /:/ /\  
   /  /:/     ___ /  /::\   /  /:/ /:/_           /__/:/ \__\:|  /  /:/ /:/_   /  /:/ /:/_   /  /:/ /:/  /  /:/ /::\ 
  /  /::\    /__/\  /:/\:\ /__/:/ /:/ /\          \  \:\ /  /:/ /__/:/ /:/ /\ /__/:/ /:/ /\ /__/:/ /:/  /__/:/ /:/\:\
 /__/:/\:\   \  \:\/:/__\/ \  \:\/:/ /:/           \  \:\  /:/  \  \:\/:/ /:/ \  \:\/:/ /:/ \  \:\/:/   \  \:\/:/~/:/
 \__\/  \:\   \  \::/       \  \::/ /:/             \  \:\/:/    \  \::/ /:/   \  \::/ /:/   \  \::/     \  \::/ /:/ 
      \  \:\   \  \:\        \  \:\/:/               \  \::/      \  \:\/:/     \  \:\/:/     \  \:\      \__\/ /:/  
       \__\/    \  \:\        \  \::/                 \__\/        \  \::/       \  \::/       \  \:\       /__/:/   
                 \__\/         \__\/                                \__\/         \__\/         \__\/       \__\/    )";

    #elif __APPLE__
        cout << "THE DEEPS";
    #else
        cout << "OS not supported!";
        exit(EXIT_FAILURE); 
    #endif

    new_line();

    sleep_for(milliseconds(1000));

    cout << "by oicleevan" << endl;

    sleep_for(milliseconds(2000));
}

bool start_menu()
{
    char c;

    title_screen();

    cout << "\nWhat will you do?" << endl
        << "    1. Start game" << endl
        << "    2. Quit" << endl;

    c = getchar();

    switch(c)
    {
        case '1': default:
            return true;
        case '2':
            return false;
    }

    return true;
}