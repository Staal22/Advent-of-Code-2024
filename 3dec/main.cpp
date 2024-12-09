#include <iostream>
#include "instruction_parser.h"

int main()
{
    const int val = instruction_parser::sum_multiply_input();
    std::cout << val << std::endl;

    return 0;
}
