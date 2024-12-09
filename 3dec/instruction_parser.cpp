//
// Created by sb on 09/12/2024.
//

#include "instruction_parser.h"
#include <fstream>
#include <string>
#include <regex>

int instruction_parser::sum_multiply_input()
{
    // Format
    // foobar{}124fk,<>'[mul(123,3)f42mul(5*,55)

    int sum = 0;

    std::regex pattern(
        R"(mul\((\d+),(\d+)\))");

    std::ifstream file("input.txt");
    std::string line;
    while (std::getline(file, line))
    {
        // Extract "mul(int,int)"
        auto line_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto line_end = std::sregex_iterator();

        for (std::sregex_iterator i = line_begin; i != line_end; ++i)
        {
            const std::smatch& match = *i;
            sum += std::stoi(match[1]) * std::stoi(match[2]);
        }
    }

    return sum;
}
