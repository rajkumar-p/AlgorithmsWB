#include "dp_algorithms.hpp"
#include <unordered_map>

unsigned int smallest_subarray_with_sum_greater_than_x(
        const std::vector<unsigned int> &numbers,
        unsigned int x)
{
    unsigned int win_sum = 0;
    unsigned int start = 0;

    unsigned int smallest_subarray = numbers.size();

    for (unsigned int end = 0; end < numbers.size(); ++end) {
        win_sum += numbers[end];

        while (win_sum > x) {
            smallest_subarray =
                    std::min(smallest_subarray, end - start + 1);
            win_sum -= numbers[start];
            ++start;
        }
    }

    return smallest_subarray;
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
