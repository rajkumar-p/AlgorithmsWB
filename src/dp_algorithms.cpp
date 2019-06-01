#include "dp_algorithms.hpp"

unsigned int smallest_subarray_with_sum_greater_than_x(
        const std::vector<unsigned int> &numbers,
        unsigned int x)
{
    unsigned int win_sum = 0;
    unsigned int start = 0;

    unsigned int smallest_subarray = numbers.size();

    for (unsigned int end = 0; end < numbers.size(); ++end) {
        win_sum += numbers[end];

        while (win_sum > x) {
            smallest_subarray =
                    std::min(smallest_subarray, end - start + 1);
            win_sum -= numbers[start];
            ++start;
        }
    }

    return smallest_subarray;
}
