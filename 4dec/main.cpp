#include <iostream>

#include "puzzle_parser.h"

int main()
{
    const int val = puzzle_parser::count_xmas();
    std::cout << val << std::endl;

    return 0;
}
