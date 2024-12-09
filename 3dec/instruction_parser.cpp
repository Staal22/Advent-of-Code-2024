//
// Created by sb on 09/12/2024.
//

#include "instruction_parser.h"
#include <fstream>
#include <string>
#include <regex>
#include <set>

int instruction_parser::sum_multiply_input()
{
    // Format
    // 2don't()foobar{}1mul(1,1)24fk,<>'[mu()l(123,3)f42mul(5*,535)3mul(77,5)

    int sum = 0;

    std::regex mul_pattern(R"(mul\((\d+),(\d+)\))");
    std::regex do_pattern(R"((do\(\)))");
    std::regex dont_pattern(R"((don't\(\)))");

    std::ifstream file("input.txt");
    std::string line;
    while (std::getline(file, line))
    {
        // Track all instructions (with data if applicable)
        std::vector<std::tuple<int, std::string, int, int>> instructions;

        auto collect_instructions = [&](const std::regex& pattern, const std::string& type)
        {
            auto line_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
            auto line_end = std::sregex_iterator();

            for (std::sregex_iterator i = line_begin; i != line_end; ++i)
            {
                if (type == "mul")
                {
                    int arg1 = std::stoi((*i)[1]);
                    int arg2 = std::stoi((*i)[2]);
                    instructions.emplace_back(i->position(), type, arg1, arg2);
                }
                else
                {
                    instructions.emplace_back(i->position(), type, 0, 0);
                }
            }
        };

        collect_instructions(mul_pattern, "mul");
        collect_instructions(do_pattern, "do");
        collect_instructions(dont_pattern, "dont");

        // Sort instructions by order of appearance
        std::ranges::sort(instructions);

        // Track enabled state and process enabled multiplies
        bool enabled = true;
        std::set<int> processed_positions;

        for (const auto& [position, type, arg1, arg2]: instructions)
        {
            if (type == "do")
                enabled = true;
            else if (type == "dont")
                enabled = false;
            else if (type == "mul" && enabled)
            {
                if (processed_positions.insert(position).second) // Only process if not already done
                {
                    sum += arg1 * arg2;
                }
                // sum += arg1 * arg2;
            }
        }
    }

    return sum;
}
