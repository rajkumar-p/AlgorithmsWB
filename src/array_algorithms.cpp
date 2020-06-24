#include "array_algorithms.hpp"
#include "searching_algorithms.hpp"

#include <numeric>
#include <unordered_map>

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

unsigned int find_pair_with_given_sum_add_memory(const std::vector<int> &numbers, int sum ) {
    unsigned int pairs = 0;
    std::unordered_map<int, unsigned int> count_map;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        if (count_map.find(numbers[i]) == count_map.end()) {
            count_map[numbers[i]] = 1;
        } else {
            count_map[numbers[i]] += 1;
        }
    }

    for (unsigned int i = 0; i < numbers.size(); ++i) {
        int to_find = sum - numbers[i];
        if (to_find == numbers[i]) {
            if (count_map[to_find] > 1) {
                ++pairs;
            }
            continue;
        }

        if (count_map.find(to_find) != count_map.end()) {
            ++pairs;
        }
    }

    return pairs;
}

unsigned int find_pair_with_given_sum_without_add_memory(std::vector<int> &numbers, int sum) {
    std::sort(numbers.begin(), numbers.end());

    unsigned int pairs = 0;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        int to_find = sum - numbers[i];
        if (to_find == numbers[i]) {
            if ((i > 0 && numbers[i - 1] == to_find) ||
                    (i + 1 < numbers.size() && numbers[i + 1] == to_find)) {
                ++pairs;
            }
            continue;
        }

        if (binary_search(numbers, to_find) != -1) {
            ++pairs;
        }
    }

    return pairs;
}

unsigned int find_pair_with_given_sum(std::vector<int> &numbers, int sum) {
    return find_pair_with_given_sum_without_add_memory(numbers, sum);
}
