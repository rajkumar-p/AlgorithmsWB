#ifndef ALGORITHMSWORKBENCH_SEARCHING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_SEARCHING_ALGORITHMS_HPP

#include <vector>

template<typename T>
int binary_search(const std::vector<T> &elements, T key)
{
    int begin = 0;
    int end = elements.size() - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (key == elements[mid]) {
            return mid;
        } else if (key < elements[mid]) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }

    return -1;
}

template<typename T>
int binary_search_leftmost(const std::vector<int> &elements, T key)
{
    int begin = 0;
    int end = elements.size() - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (key <= elements[mid]) {
            end = mid - 1;
        } else if (key > elements[mid]) {
            begin = mid + 1;
        }
    }

    if (begin >= elements.size() || elements[begin] != key) {
        return -1;
    }

    return begin;
}

template<typename T>
int binary_search_rightmost(const std::vector<T> &elements, T key)
{
    int begin = 0;
    int end = elements.size() - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (key >= elements[mid]) {
            begin = mid + 1;
        } else if (key < elements[mid]) {
            end = mid - 1;
        }
    }

    if (end >= elements.size() || elements[end] != key) {
        return -1;
    }

    return end;
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
