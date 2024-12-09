#include <algorithm>
#include <iostream>
#include <ostream>
#include "list_parser.h"

int main()
{
    // Get lists from input data
    auto location_id_lists = list_parser::get_lists();
    auto l_list = location_id_lists.first;
    auto r_list = location_id_lists.second;

    // Sort the lists
    std::ranges::sort(l_list);
    std::ranges::sort(r_list);

    // --- Part One ---
    // Sum up the difference of the IDs in respective ascending orders
    int distance_total = 0;
    for (int i = 0; i < l_list.size(); ++i)
    {
        distance_total += abs(l_list[i] - r_list[i]);
    }

    std::cout << "Part One: " << distance_total << std::endl;

    // --- Part Two ---
    int similarity_score_total = 0;
    for (const int left : l_list)
    {
        int occurs = 0;
        for (const int right : r_list)
        {
            if (left == right) occurs++;
        }
        similarity_score_total += left * occurs;
    }

    std::cout << "Part Two: " << similarity_score_total << std::endl;

    return 0;
}
