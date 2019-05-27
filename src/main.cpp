#include <iostream>
#include "sorting_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> numbers;
    numbers = {2, 1, 5, 2, 3, 2};

    insertion_sort(numbers);

    for (const int number : numbers) {
        std::cout << number << "\t";
    }
    std::cout <<std::endl;

    return 0;
}