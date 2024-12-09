#include <iostream>
#include "instruction_parser.h"

int main()
{
    // --- Part One ---
    int val = instruction_parser::sum_multiply_input();
    std::cout << "Part One: " << val << std::endl;

    // --- Part Two ---
    val = instruction_parser::sum_multiply_input_v2();
    std::cout << "Part Two: " << val << std::endl;

    return 0;
}
