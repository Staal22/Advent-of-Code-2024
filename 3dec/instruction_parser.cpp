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
    // 2don't()foobar{}1mul(1,1)24fk,<>'[mu()l(123,3)f42mul(5*,535)3mul(77,5)

    int sum = 0;

    // Regex pattern to match mul instruction
    std::regex pattern(R"(mul\((\d+),(\d+)\))");

    std::ifstream file("input.txt");
    std::string content((std::istreambuf_iterator(file)),
                        std::istreambuf_iterator<char>());

    auto matches_begin = std::sregex_iterator(content.begin(), content.end(), pattern);
    auto matches_end = std::sregex_iterator();

    // Go through the text (matches) and multiply
    for (std::sregex_iterator i = matches_begin; i != matches_end; ++i)
    {
        const std::smatch& match = *i;
        int arg1 = std::stoi(match[1]);
        int arg2 = std::stoi(match[2]);
        sum += arg1 * arg2;
    }

    return sum;
}

int instruction_parser::sum_multiply_input_v2()
{
    int sum = 0;

    // Regex pattern to match mul instruction or either of the conditionals
    std::regex combined_pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");

    std::ifstream file("input.txt");
    std::string content((std::istreambuf_iterator(file)),
                        std::istreambuf_iterator<char>());

    auto matches_begin = std::sregex_iterator(content.begin(), content.end(), combined_pattern);
    auto matches_end = std::sregex_iterator();

    bool enabled = true;

    // Go through the text (matches) and flip enabled state based on conditionals
    for (std::sregex_iterator i = matches_begin; i != matches_end; ++i)
    {
        const std::smatch& match = *i;

        if (match[0].str().find("do()") != std::string::npos)
        {
            enabled = true;
        }
        else if (match[0].str().find("don't()") != std::string::npos)
        {
            enabled = false;
        }
        // If enabled, do matched multiplication
        else if (match[0].str().find("mul(") != std::string::npos && enabled)
        {
            int arg1 = std::stoi(match[1]);
            int arg2 = std::stoi(match[2]);
            sum += arg1 * arg2;
        }
    }

    return sum;
}
