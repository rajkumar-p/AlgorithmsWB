#ifndef ALGORITHMSWORKBENCH_UTILS_H
#define ALGORITHMSWORKBENCH_UTILS_H

#include <random>
#include <vector>

template<typename T>
std::vector<T> get_random_numbers(T start, T end, unsigned int count)
{
    std::mt19937 rand_engine;
    std::uniform_int_distribution<int> dist(start, end);

    std::vector<T> randoms(count);
    for (unsigned int i = 0; i < count; ++i) {
        randoms[i] = dist(rand_engine);
    }

    return randoms;
}

#endif //ALGORITHMSWORKBENCH_UTILS_H