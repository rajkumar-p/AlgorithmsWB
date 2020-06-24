#include <iostream>
#include "array_algorithms.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Hello world!!!" << std::endl;
    std::vector<int> numbers;
    int sum;

    numbers = {8, 7, 2, 5, 3, 1};
    sum = 16;
    find_pair_with_given_sum(numbers, sum);
    return 0;
}