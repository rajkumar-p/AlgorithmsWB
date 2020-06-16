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
    int rolling_sum = 0;
    for (unsigned int i = 0; i < k; ++i) {
        rolling_sum += numbers[i];
    }

    max_sum = std::max(max_sum, rolling_sum);
    for (unsigned int i = k; i < numbers.size(); ++i) {
        rolling_sum += numbers[i];
        rolling_sum -= numbers[i - k];
        max_sum = std::max(max_sum, rolling_sum);
    }

    return max_sum;
}

void rotate_elements(std::vector<int> &numbers, unsigned int k)
{
    for (unsigned int start = 0, end = numbers.size() - 1; start < end; ++start, --end) {
        std::swap(numbers[start], numbers[end]);
    }

    for (unsigned int start = 0, end = k - 1; start < end; ++start, --end) {
        std::swap(numbers[start], numbers[end]);
    }

    for (unsigned int start = k, end = numbers.size() - 1; start < end; ++start, --end) {
        std::swap(numbers[start], numbers[end]);
    }
}

void replace_array_with_right_side_sum(std::vector<int> &numbers)
{
    int right_sum = 0;
    for (int i = numbers.size() - 1; i >= 0; --i) {
        int add = numbers[i];
        numbers[i] = right_sum;
        right_sum += add;
    }
}
