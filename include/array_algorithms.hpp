#ifndef ALGORITHMSWORKBENCH_ARRAY_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_ARRAY_ALGORITHMS_HPP

#include <vector>

// https://www.geeksforgeeks.org/find-maximum-average-subarray-of-k-length/
// Similar problem, but return all the averages in a std::vector<int>
std::vector<double> max_avg_subarray_of_size_k(const std::vector<int> &numbers, size_t k);

// https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/
int max_sum_subarray_of_size_k(const std::vector<int> &numbers, size_t k);

// https://dev.to/alisabaj/not-an-easy-algorithm-rotating-an-array-three-ways-2f6h
void rotate_elements(std::vector<int> &numbers, unsigned int k);

void replace_array_with_right_side_sum(std::vector<int> &numbers);

// http://www.techiedelight.com/find-pair-with-given-sum-array/
unsigned int find_pair_with_given_sum(std::vector<int> &numbers, int sum);

// http://www.techiedelight.com/find-sub-array-with-0-sum/
std::vector<std::pair<unsigned int, unsigned int>> get_subarrays_with_sum_0(
        const std::vector<int> &numbers);

// http://www.techiedelight.com/find-duplicate-element-limited-range-array/
unsigned int find_the_one_duplicate(std::vector<int> &numbers);

// http://www.techiedelight.com/find-largest-sub-array-formed-by-consecutive-integers/
unsigned int largest_subarray_with_consecutive_ints(const std::vector<int> &numbers);

// http://www.techiedelight.com/find-maximum-length-sub-array-having-given-sum/
unsigned int max_len_subarray_having_sum_k(const std::vector<int> &numbers, int k);

// http://www.techiedelight.com/find-maximum-length-sub-array-equal-number-0s-1s/
unsigned int max_len_subarray_having_equal_0s_and_1s(const std::vector<unsigned int> &numbers);

// http://www.techiedelight.com/move-zeros-present-array-end/
void move_all_zeros_to_end(std::vector<int> &numbers);

// http://www.techiedelight.com/merge-two-arrays-satisfying-given-constraints/
void merge_to_partially_filled_array(std::vector<int> &partial, const std::vector<int> &rest);

// http://www.techiedelight.com/find-maximum-product-two-integers-array/
int max_product_with_two_elements(const std::vector<int> &numbers);

// http://www.techiedelight.com/find-index-0-replaced-get-maximum-length-sequence-of-continuous-ones/
unsigned int get_index_to_replace_to_maximize_1s(const std::vector<unsigned short> &numbers);

#endif //ALGORITHMSWORKBENCH_ARRAY_ALGORITHMS_HPP
