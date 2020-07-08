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

void sort_array_with_0_1_2(std::vector<unsigned short> &numbers)
{
    unsigned int count[] = {0, 0, 0};
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        count[numbers[i]] += 1;
    }

    for (unsigned int i = 0, glob_index = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < count[i]; ++j) {
            numbers[glob_index++] = static_cast<unsigned short>(i);
        }
    }
}

void sort_array_with_0_1_2_V2(std::vector<unsigned short> &numbers)
{
    int start = 0;
    int mid = 0;
    int end = numbers.size() - 1;

    while (mid <= end) {
        if (numbers[mid] > 1) {
            std::swap(numbers[mid], numbers[end]);
            --end;
        } else if (numbers[mid] < 1) {
            std::swap(numbers[start], numbers[mid]);
            ++start;
            ++mid;
        } else {
            ++mid;
        }
    }
}
