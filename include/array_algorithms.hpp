#ifndef ALGORITHMSWORKBENCH_ARRAY_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_ARRAY_ALGORITHMS_HPP

#include <vector>

// https://www.geeksforgeeks.org/find-maximum-average-subarray-of-k-length/
// Similar problem, but return all the averages in a std::vector<int>
std::vector<double> max_avg_subarray_of_size_k(const std::vector<int> &numbers, size_t k);

//https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/
int max_sum_subarray_of_size_k(const std::vector<int> &numbers, size_t k);

// https://dev.to/alisabaj/not-an-easy-algorithm-rotating-an-array-three-ways-2f6h
void rotate_elements(std::vector<int> &numbers, unsigned int k);

void replace_array_with_right_side_sum(std::vector<int> &numbers);

// http://www.techiedelight.com/find-pair-with-given-sum-array/
unsigned int find_pair_with_given_sum(std::vector<int> &numbers, int sum);

#endif //ALGORITHMSWORKBENCH_ARRAY_ALGORITHMS_HPP
