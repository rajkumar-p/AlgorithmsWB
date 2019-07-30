#include "array_algorithms.hpp"
#include <numeric>

std::vector<double> max_avg_subarray_of_size_k(const std::vector<int> &numbers, size_t k)
{
    std::vector<double> result;

    if (numbers.size() < k) {
        int sum = 0;
        std::accumulate(numbers.begin(), numbers.end(), sum);

        result.push_back(sum / k);
        return result;
    }

    int previous_sum = 0;
    previous_sum = std::accumulate(numbers.begin(), numbers.begin() + k, previous_sum);
    result.push_back(previous_sum / double(k));

    size_t first = 0, last = k;
    while (last < numbers.size()) {
        previous_sum -= numbers[first];
        previous_sum += numbers[last];

        result.push_back(previous_sum / double(k));

        ++first;
        ++last;
    }

    return result;
}

int max_sum_subarray_of_size_k(const std::vector<int> &numbers, size_t k)
{
    if (numbers.size() < k) {
        return std::accumulate(numbers.begin(), numbers.end(), 0);
    }

    int max_sum = 0;
    int current_sum = 0;
    for (size_t i = 0; i < k; ++i) {
        current_sum += numbers[i];
    }
    max_sum = current_sum;

    for (size_t i = k, begin = 0; i < numbers.size(); ++i, ++begin) {
        current_sum = current_sum + numbers[i] - numbers[begin];
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum;
}
