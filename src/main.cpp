#include <iostream>
#include <vector>
#include "array_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> numbers = {1, 12, -5, -6, 50, 3};
    std::vector<double> result = max_avg_subarray_of_size_k(numbers, 4);

    for (double avg : result) {
        std::cout <<avg<<std::endl;
    }

    return 0;
}