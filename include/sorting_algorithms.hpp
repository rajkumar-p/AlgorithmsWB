#ifndef ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP

#include <vector>

// Insertion Sort
template<typename T>
void insertion_sort(std::vector<T> &elements)
{
    for(size_t i = 1; i < elements.size(); ++i) {
        T key = elements[i];
        int j = i - 1;
        while(j >= 0 && elements[j] > key) {
            elements[j + 1] = elements[j];
            --j;
        }

        elements[j + 1] = key;
    }
}

#endif //ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
