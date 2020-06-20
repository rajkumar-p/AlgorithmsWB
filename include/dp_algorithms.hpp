#ifndef ALGORITHMSWORKBENCH_DP_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_DP_ALGORITHMS_HPP

#include <vector>
#include <string>

// https://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/
unsigned int smallest_subarray_with_sum_greater_than_x(
        const std::vector<unsigned int> &numbers,
        unsigned int x);

// https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
unsigned int longest_substr_with_k_unqiue_chars(const std::string &str, unsigned int k);

// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
unsigned int longest_substr_with_unique_chars(std::string &str);

// https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/
unsigned int longest_subarray_with_1s_by_changing_atmost_k_0s(const std::string &str,
                                                              unsigned int k);

#endif //ALGORITHMSWORKBENCH_DP_ALGORITHMS_HPP
