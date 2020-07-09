#include "array_algorithms.hpp"
#include "searching_algorithms.hpp"

#include <numeric>
#include <unordered_map>

std::vector<double> max_avg_subarray_of_size_k(const std::vector<int> &numbers, size_t k) {
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

int max_sum_subarray_of_size_k(const std::vector<int> &numbers, size_t k) {
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

void rotate_elements(std::vector<int> &numbers, unsigned int k) {
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

void replace_array_with_right_side_sum(std::vector<int> &numbers) {
    int right_sum = 0;
    for (int i = numbers.size() - 1; i >= 0; --i) {
        int add = numbers[i];
        numbers[i] = right_sum;
        right_sum += add;
    }
}

unsigned int find_pair_with_given_sum_add_memory(const std::vector<int> &numbers, int sum) {
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

std::vector<std::pair<unsigned int, unsigned int>> get_subarrays_with_sum_0(
        const std::vector<int> &numbers) {
    std::vector<std::pair<unsigned int, unsigned int>> result;

    std::unordered_map<int, unsigned int> sum_map;
    int sum = 0;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 0) {
            result.push_back(std::make_pair(i, i));
            continue;
        }

        sum += numbers[i];
        if (sum == 0) {
            result.push_back(std::make_pair(0, i));
        }

        if (sum_map.find(sum) != sum_map.end()) {
            result.push_back(std::make_pair(sum_map[sum] + 1, i));
        }

        sum_map[sum] = i;
    }

    return result;
}

unsigned int find_the_one_duplicate_using_pos_neg(std::vector<int> &numbers) {
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        unsigned int index = std::abs(numbers[i]) - 1;
        if (numbers[index] < 0) {
            return std::abs(numbers[i]);
        }

        numbers[index] *= -1;
    }

    return 0;
}

unsigned int find_the_one_duplicate(std::vector<int> &numbers)
{
    return find_the_one_duplicate_using_pos_neg(numbers);
}

unsigned int largest_subarray_with_consecutive_ints(const std::vector<int> &numbers)
{
    unsigned int max_len = 1;
    std::unordered_map<int, bool> seen_elements;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        int win_min = numbers[i];
        int win_max = numbers[i];
        seen_elements[numbers[i]] = true;
        for (unsigned int j = i + 1; j < numbers.size() &&
                seen_elements.find(numbers[j]) == seen_elements.end(); ++j) {
            win_min = std::min(win_min, numbers[j]);
            win_max = std::max(win_max, numbers[j]);
            if (static_cast<unsigned int>(win_max - win_min) <= j - i) {
                unsigned int curr_len = j - i + 1;
                max_len = std::max(max_len, curr_len);
            }
            seen_elements[numbers[j]] = true;
        }

        seen_elements.clear();
    }

    return max_len;
}

unsigned int max_len_subarray_having_sum_k(const std::vector<int> &numbers, int k)
{
    unsigned int max_len = 0;
    std::unordered_map<int, int> sum_map;
    sum_map[0] = -1;

    int curr_sum = 0;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        curr_sum += numbers[i];
        if (sum_map.find(curr_sum) == sum_map.end()) {
            sum_map[curr_sum] = i;
        }

        if (sum_map.find(curr_sum - k) != sum_map.end()) {
            unsigned int curr_len = i - (sum_map[curr_sum - k] + 1) + 1;
            max_len = std::max(max_len, curr_len);
        }
    }

    return max_len;
}

unsigned int max_len_subarray_having_equal_0s_and_1s(const std::vector<unsigned int> &numbers)
{
    unsigned int max_len = 0;
    std::unordered_map<int, unsigned int> sum_map;
    int curr_sum = 0;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 0) {
            curr_sum += -1;
        } else {
            curr_sum += 1;
        }

        if (sum_map.find(curr_sum) == sum_map.end()) {
            sum_map[curr_sum] = i;
        } else {
            unsigned int curr_len = i - (sum_map[curr_sum] + 1) + 1;
            max_len = std::max(max_len, curr_len);
        }
    }

    return max_len;
}

void move_all_zeros_to_end(std::vector<int> &numbers)
{
    unsigned int jump = 0;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 0) {
            ++jump;
        } else {
            std::swap(numbers[i], numbers[i - jump]);
        }
    }
}

void merge_to_partially_filled_array(std::vector<int> &partial, const std::vector<int> &rest)
{
    for (int i = partial.size() - 1, insert = i; i >= 0; --i) {
        if (partial[i] != 0) {
            std::swap(partial[insert--], partial[i]);
        }
    }

    unsigned int insert = 0;
    unsigned int partial_index = rest.size();
    unsigned int rest_index = 0;
    while (rest_index < rest.size() && partial_index < partial.size()) {
        if (partial[partial_index] < rest[rest_index]) {
            partial[insert++] = partial[partial_index++];
        } else {
            partial[insert++] = rest[rest_index++];
        }
    }

    while (rest_index < rest.size()) {
        partial[insert++] = rest[rest_index++];
    }

    while (partial_index < partial.size()) {
        partial[insert++] = partial[partial_index++];
    }
}

int max_product_with_two_elements(const std::vector<int> &numbers)
{
    int first_max = std::numeric_limits<int>::min();
    int second_max = std::numeric_limits<int>::min();

    int first_min = std::numeric_limits<int>::max();
    int second_min = std::numeric_limits<int>::max();

    for (unsigned int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] > first_max) {
            second_max = first_max;
            first_max = numbers[i];
        } else if (numbers[i] > second_max) {
            second_max = numbers[i];
        }

        if (numbers[i] < first_min) {
            second_min = first_min;
            first_min = numbers[i];
        } else if (numbers[i] < second_min) {
            second_min = numbers[i];
        }
    }

    return std::max(first_max * second_max, first_min * second_min);
}

unsigned int get_index_to_replace_to_maximize_1s(const std::vector<unsigned short> &numbers)
{
    unsigned int index_to_replace = 0;
    unsigned int max_len = 0;

    unsigned int zero_count = 0;
    unsigned int last_seen_zero = 0;
    for (unsigned head = 0, tail = 0; tail < numbers.size(); ++tail) {
        if (numbers[tail] == 0) {
            ++zero_count;
            last_seen_zero = tail;
        }

        while (head < tail && zero_count > 1) {
            if (numbers[head] == 0) {
                --zero_count;
            }

            ++head;
        }

        unsigned int curr_len = tail - head + 1;
        if (curr_len > max_len) {
            max_len = curr_len;
            index_to_replace = last_seen_zero;
        }
    }

    return index_to_replace;
}
