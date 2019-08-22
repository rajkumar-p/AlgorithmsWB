#ifndef ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP

#include <functional>
#include <vector>

/*
 * Method Definitions
 */
// Insertion Sort
template<typename T,
        typename F = std::function<bool(T, T)>>
void insertion_sort(std::vector<T> &elements,
        F cmp_fn = std::less<T>());

// Selection Sort
template<typename T,
        typename F = std::function<bool(T, T)>>
void selection_sort(std::vector<T> &elements,
        F cmp_fn = std::less<T>());

/*
 * Method Implementations
 */
// Insertion sort
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

// Selection Sort
template<typename T, typename F>
void selection_sort(std::vector<T> &elements, F cmp_fn)
{
    for (size_t i = 0; i < elements.size(); ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < elements.size(); ++j) {
            if (cmp_fn(elements[j], elements[min_index])) {
                min_index = j;
            }
        }
        std::swap(elements[i], elements[min_index]);
    }
}

#endif //ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
