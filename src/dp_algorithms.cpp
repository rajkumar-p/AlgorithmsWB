#include "dp_algorithms.hpp"
#include <unordered_map>

unsigned int smallest_subarray_with_sum_greater_than_x(
        const std::vector<unsigned int> &numbers,
        unsigned int x)
{
    unsigned int window_sum = 0;
    unsigned int smallest_subarr_size = numbers.size();
    for (unsigned int head = 0, tail = 0; tail < numbers.size(); ++tail) {
        window_sum += numbers[tail];
        while (window_sum - numbers[head] > x) {
            window_sum -= numbers[head];
            ++head;

            unsigned int current_subarr_size = tail - head + 1;
            smallest_subarr_size =
                    std::min(smallest_subarr_size, current_subarr_size);
        }
    }

    return smallest_subarr_size;
}

unsigned int longest_substr_with_k_unqiue_chars(
        const std::string &str, unsigned int k)
{
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
