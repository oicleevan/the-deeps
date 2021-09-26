#include <iostream>

#include "libeo.h"

namespace libeo
{
    void clrscr()
    {
        std::cout << "\033[2J\033[1;1H";
        return;
    }

    unsigned int gen_rand(int number)
    {
        return std::rand() % number + 1;
    }

    void new_line() { std::cout << std::endl; }
}