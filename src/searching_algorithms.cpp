#include <unordered_map>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp"

bool sub_optimal_if_exits_x_and_y_equals_sum(std::vector<int> &elements,
        const int sum)
{
    merge_sort(elements);
    for (const int e : elements) {
        int inverse = sum - e;
        if (binary_search(elements, inverse) != -1) {
            return true;
        }
    }

    return false;
}

bool if_exits_x_and_y_equals_sum(const std::vector<int> &elements,
                                 const int sum)
{
    std::unordered_map<int, bool> map;
    for (const int e : elements) {
        map[e] = true;
    }

    for (const int e : elements) {
        int inverse = sum - e;
        if (map.find(inverse) != map.end()) {
            return true;
        }
    }

    return false;
}
