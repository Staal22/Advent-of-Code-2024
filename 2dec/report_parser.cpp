//
// Created by sb on 08/12/2024.
//

#include "report_parser.h"
#include <fstream>
#include <iosfwd>
#include <sstream>

std::vector<std::vector<int>> report_parser::get_reports()
{
    // Format
    // 19 21 24 27 24
    // 85 87 89 92 93 96 98 98

    std::vector<std::vector<int>> reports;

    std::ifstream file("reports.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::vector<int> row;
        int val;
        while (ss >> val)
        {
            row.push_back(val);
        }

        reports.push_back(row);
    }

    return reports;
}
