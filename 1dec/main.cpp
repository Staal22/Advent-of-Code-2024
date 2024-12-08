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

    // Sum up the difference of the IDs in respective ascending orders
    int sum = 0;
    for (int i = 0; i < l_list.size(); ++i)
    {
        sum += abs(l_list[i] - r_list[i]);
    }

    std::cout << sum << std::endl;

    return 0;
}
