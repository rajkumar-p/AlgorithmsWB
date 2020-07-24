#include "utils.h"

template<>
std::vector<float> get_random_numbers(float start, float end, unsigned int count) {
    std::mt19937 rand_engine;
    std::uniform_real_distribution<float> dist(start, end);

    std::vector<float> randoms(count);
    for (unsigned int i = 0; i < count; ++i) {
        randoms[i] = dist(rand_engine);
    }

    return randoms;
}

template<>
std::vector<double> get_random_numbers(double start, double end, unsigned int count) {
    std::mt19937 rand_engine;
    std::uniform_real_distribution<double> dist(start, end);

    std::vector<double> randoms(count);
    for (unsigned int i = 0; i < count; ++i) {
        randoms[i] = dist(rand_engine);
    }

    return randoms;
}
