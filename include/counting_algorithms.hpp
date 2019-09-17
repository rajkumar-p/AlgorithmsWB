#ifndef ALGORITHMSWORKBENCH_COUNTING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_COUNTING_ALGORITHMS_HPP

#include <functional>

// https://www.geeksforgeeks.org/counting-inversions/
template<typename T,
        typename F = std::function<bool(T, T)>>
size_t count_inversions(std::vector<T> &elements,
                        F cmp_fn = std::less<T>());

template<typename T,
        typename F>
size_t count_inversions(std::vector<T> &elements,
                        F cmp_fn)
{
    size_t inversions = 0;
    for (size_t i = 1; i < elements.size(); ++i) {
        T key = elements[i];
        int j = i - 1;
        while (j >= 0 && cmp_fn(key, elements[j])) {
            elements[j + 1] = elements[j];
            --j;
        }
        inversions = inversions + i - j - 1;
        elements[j + 1] = key;
    }

    return inversions;
}

#endif //ALGORITHMSWORKBENCH_COUNTING_ALGORITHMS_HPP
