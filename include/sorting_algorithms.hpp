#ifndef ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP

#include <functional>
#include <vector>

// Insertion Sort
template<typename T,
        typename F = std::function<bool(T, T)>>
void insertion_sort(std::vector<T> &elements,
        F cmp_fn = std::less<T>());

template<typename T, typename F>
void insertion_sort(std::vector<T> &elements, F cmp_fn)
{
    for(size_t i = 1; i < elements.size(); ++i) {
        T key = elements[i];
        int j = i - 1;
        while(j >= 0 && cmp_fn(key, elements[j])) {
            elements[j + 1] = elements[j];
            --j;
        }

        elements[j + 1] = key;
    }
}

#endif //ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
