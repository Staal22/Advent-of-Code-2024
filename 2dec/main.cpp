#include <iostream>
#include <ostream>
#include "report_parser.h"

bool problem_encountered(const std::vector<int>& report)
{
    for (int i = 0; i < report.size(); ++i)
    {
        auto modified_report = report;
        modified_report.erase(modified_report.begin() + i);
        if (modified_report.size() == 1) return true;

        bool ascending = true;
        if (modified_report[0] > modified_report[1]) ascending = false;
        for (int j = 0; j < modified_report.size() - 1; ++j)
        {
            if (modified_report[j] == modified_report[j + 1]) break;
            if (abs(modified_report[j] - modified_report[j + 1]) > 3) break;
            if (ascending)
            {
                if (modified_report[j] > modified_report[j + 1]) break;
            }
            else
            {
                if (modified_report[j] < modified_report[j + 1]) break;
            }
            if (j == modified_report.size() - 2) return true;
        }
    }
    return false;
}

bool is_report_safe(const std::vector<int>& report)
{
    if (report.size() == 1) return true;

    bool ascending = true;
    if (report[0] > report[1]) ascending = false;
    for (int i = 0; i < report.size() - 1; ++i)
    {
        if (report[i] == report[i + 1])
            return problem_encountered(report);
        if (abs(report[i] - report[i + 1]) > 3)
            return problem_encountered(report);
        if (ascending)
        {
            if (report[i] > report[i + 1])
                return problem_encountered(report);
        }
        else
        {
            if (report[i] < report[i + 1])
                return problem_encountered(report);
        }
    }

    return true;
}

int main()
{
    const auto reports = report_parser::get_reports();
    int safe_reports = 0;

    for (const auto& report: reports)
    {
        if (is_report_safe(report)) safe_reports++;
    }

    std::cout << safe_reports << std::endl;

    return 0;
}
