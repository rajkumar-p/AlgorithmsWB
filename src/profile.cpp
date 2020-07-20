#include <algorithm>
#include <cassert>
#include <iostream>

#include "sorting_algorithms.hpp"

std::vector<unsigned int> read_input()
{
    unsigned int N;
    std::cin >> N;

    std::vector<unsigned int> numbers(N);
    for (unsigned int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    return numbers;
}

int main(int argc, char *argv[])
{
    std::vector<unsigned int> numbers = read_input();
    std::vector<unsigned int> numbers_to_sort;

    numbers_to_sort.assign(numbers.begin(), numbers.end());
    std::cout << "Running bubble sort on "<< numbers_to_sort.size()
              << " elements" << std::endl;
    bubble_sort(numbers_to_sort);
    assert(std::is_sorted(numbers_to_sort.begin(), numbers_to_sort.end()));

    numbers_to_sort.assign(numbers.begin(), numbers.end());
    std::cout << "Running selection sort on "<< numbers_to_sort.size()
              << " elements" << std::endl;
    selection_sort(numbers_to_sort);
    assert(std::is_sorted(numbers_to_sort.begin(), numbers_to_sort.end()));

    numbers_to_sort.assign(numbers.begin(), numbers.end());
    std::cout << "Running insertion sort on "<< numbers_to_sort.size()
              << " elements" << std::endl;
    insertion_sort(numbers_to_sort);
    assert(std::is_sorted(numbers_to_sort.begin(), numbers_to_sort.end()));

    numbers_to_sort.assign(numbers.begin(), numbers.end());
    std::cout << "Running merge sort on "<< numbers_to_sort.size()
              << " elements" << std::endl;
    merge_sort(numbers_to_sort);
    assert(std::is_sorted(numbers_to_sort.begin(), numbers_to_sort.end()));

    return 0;
}