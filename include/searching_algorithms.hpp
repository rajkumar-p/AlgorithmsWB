#ifndef ALGORITHMSWORKBENCH_SEARCHING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_SEARCHING_ALGORITHMS_HPP

#include <vector>

template<typename T>
int binary_search(const std::vector<T> &elements, T key);
template<typename T>
int binary_search_helper(const std::vector<T> &elements,
        int begin, int end, T key);

template<typename T>
int binary_search(const std::vector<T> &elements, T key)
{
    return binary_search_helper(elements, 0, elements.size() - 1, key);
}

template<typename T>
int binary_search_helper(const std::vector<T> &elements,
        int begin, int end, T key)
{
    if (begin > end) {
        return -1;
    }

    int middle = begin + ((end - begin) / 2);
    if (elements[middle] == key) {
        return middle;
    } else if (elements[middle] < key) {
        return binary_search_helper(elements, middle + 1, end, key);
    } else {
        return binary_search_helper(elements, begin, middle - 1, key);
    }
}

#endif //ALGORITHMSWORKBENCH_SEARCHING_ALGORITHMS_HPP
