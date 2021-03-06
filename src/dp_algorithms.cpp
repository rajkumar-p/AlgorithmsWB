#include "dp_algorithms.hpp"

#include <algorithm>
#include <unordered_map>

unsigned int smallest_subarray_with_sum_greater_than_x(
        const std::vector<unsigned int> &numbers, unsigned int x) {
    unsigned int subarray_size = numbers.size();
    unsigned int window_sum = 0;
    for (unsigned int start = 0, end = 0; end < numbers.size(); ++end) {
        window_sum += numbers[end];
        if (window_sum <= x) {
            continue;
        }

        while (start < end && window_sum - numbers[start] > x) {
            window_sum -= numbers[start];
            ++start;
        }

        unsigned int curr_subarray_count = end - start + 1;
        subarray_size = std::min(subarray_size, curr_subarray_count);
    }

    return subarray_size;
}

unsigned int longest_substr_with_k_unqiue_chars(const std::string &str,
                                                unsigned int k) {
    std::unordered_map<char, unsigned int> char_map;
    unsigned int longest_substr = 0;
    for (unsigned int head = 0, tail = 0; tail < str.length(); ++tail) {
        if (char_map.find(str[tail]) == char_map.end()) {
            char_map[str[tail]] = 1;
        } else {
            char_map[str[tail]] += 1;
        }

        while (head < tail && char_map.size() > k) {
            if (char_map[str[head]] == 1) {
                char_map.erase(str[head]);
            } else {
                char_map[str[head]] -= 1;
            }

            ++head;
        }

        unsigned int current_max_substr = tail - head + 1;
        longest_substr = std::max(longest_substr, current_max_substr);
    }

    return longest_substr;
}

unsigned int longest_substr_with_unique_chars(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    int char_arr[26] = {0};
    unsigned int longest_substr_len = 0;
    for (unsigned int start = 0, end = 0; end < str.length(); ++end) {
        char_arr[str[end] - 65] += 1;
        while (start < end && char_arr[str[end] - 65] > 1) {
            char_arr[str[start] - 65] -= 1;
            ++start;
        }

        unsigned int window_len = end - start + 1;
        longest_substr_len = std::max(longest_substr_len, window_len);
    }

    return longest_substr_len;
}

unsigned int longest_subarray_with_1s_by_changing_atmost_k_0s(const std::string &str,
                                                              unsigned int k) {
    unsigned int longest_subarray_len = 0;
    unsigned int win_zero_count = 0;
    for (unsigned int start = 0, end = 0; end < str.length(); ++end) {
        if (str[end] == '0') {
            ++win_zero_count;
        }

        while (start < end && win_zero_count > k) {
            if (str[start] == '0') {
                --win_zero_count;
            }
            ++start;
        }

        unsigned int ones_count = end - start + 1;
        longest_subarray_len = std::max(longest_subarray_len, ones_count);
    }

    return longest_subarray_len;
}
