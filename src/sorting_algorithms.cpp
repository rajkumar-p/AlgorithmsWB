#include "sorting_algorithms.hpp"

void sort_binary_array(std::vector<bool> &numbers)
{
    unsigned int boundary = 0;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 0) {
            std::swap(numbers[boundary++], numbers[i]);
        }
    }
}
