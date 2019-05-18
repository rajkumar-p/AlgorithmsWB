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
