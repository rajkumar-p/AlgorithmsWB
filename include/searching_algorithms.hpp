#ifndef ALGORITHMSWORKBENCH_SEARCHING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_SEARCHING_ALGORITHMS_HPP

#include <vector>

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

template<typename T>
int binary_search(const std::vector<T> &elements, T key)
{
    return binary_search_helper(elements, 0, elements.size() - 1, key);
}

template<typename T>
int binary_search_leftmost_helper(const std::vector<int> &elements,
                                  int begin, int end, T key)
{
    if (begin >= end) {
        if (elements[begin] == key) {
            return begin;
        } else {
            return -1;
        }
    }

    int middle = begin + ((end - begin) / 2);
    if (elements[middle] < key) {
        return binary_search_leftmost_helper(elements, middle + 1, end, key);
    } else {
        return binary_search_leftmost_helper(elements, begin, middle, key);
    }
}

template<typename T>
int binary_search_leftmost(const std::vector<int> &elements, T key)
{
    return binary_search_leftmost_helper(elements, 0, elements.size() - 1, key);
}

template<typename T>
int binary_search_rightmost_helper(const std::vector<T> &elements,
                                   int begin, int end, T key)
{
    // To implement
    return -1;
}

template<typename T>
int binary_search_rightmost(const std::vector<T> &elements, T key)
{
    return binary_search_rightmost_helper(elements, 0, elements.size() - 1, key);
}

/*
 * This is a sub-optimal algorithm to find, in a set of integers - elements,
 * if there exists two elements, x and y - whose sum is sum.
 * The running time for this algorithm is O(n lg n)
 */
bool sub_optimal_if_exits_x_and_y_equals_sum(std::vector<int> &elements,
        const int sum);

bool if_exits_x_and_y_equals_sum(const std::vector<int> &elements,
                                             const int sum);
#endif //ALGORITHMSWORKBENCH_SEARCHING_ALGORITHMS_HPP
