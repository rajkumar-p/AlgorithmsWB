#include "dp_algorithms.hpp"

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

        while (char_map.size() > k) {
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

unsigned int longest_substr_with_unique_chars(const std::string &str) {
    std::unordered_map<char, unsigned int> char_last_pos;
    unsigned int longest_substr = 0;
    for (unsigned int head = 0, tail = 0; tail < str.length(); ++tail) {
        if (char_last_pos.find(str[tail]) != char_last_pos.end()) {
            head = std::max(head, char_last_pos[str[tail]] + 1);
        }

        char_last_pos[str[tail]] = tail;
        longest_substr = std::max(longest_substr, tail - head + 1);
    }

    return longest_substr;
}
