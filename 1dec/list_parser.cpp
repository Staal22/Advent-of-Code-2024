//
// Created by sb on 08/12/2024.
//

#include "list_parser.h"
#include <fstream>
#include <ranges>
#include <sstream>
#include <string>

std::pair<std::vector<int>, std::vector<int>> list_parser::get_lists()
{
    // Format
    // l       r
    // 77710   11556
    // 22632   23674

    std::vector<int> l_list;
    std::vector<int> r_list;

    std::ifstream file("input.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        int l_val, r_val;

        // Parse left and right values
        if (iss >> l_val >> r_val)
        {
            l_list.push_back(l_val);
            r_list.push_back(r_val);
        }
    }

    return std::make_pair(l_list, r_list);
}
