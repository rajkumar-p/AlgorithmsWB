#include "catch.hpp"
#include "array_algorithms.hpp"

TEST_CASE("max_avg_subarray_of_size_k() tests", "[max_avg_subarray_of_size_k() tests]")
{
    std::vector<int> numbers;
    size_t k;

    std::vector<double> result;

    numbers = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    k = 5;

    result = {2.2, 2.8, 2.4, 3.6, 2.8};
    REQUIRE(max_avg_subarray_of_size_k(numbers, k) == result);

    numbers = {1, 12, -5, -6, 50, 3};
    k = 4;

    result = {0.5, 12.75, 10.5};
    REQUIRE(max_avg_subarray_of_size_k(numbers, k) == result);
}

TEST_CASE("max_sum_subarray_of_size_k() tests", "[max_sum_subarray_of_size_k() tests]")
{
    std::vector<int> numbers;
    size_t k;

    numbers = {2, 1, 5, 1, 3, 2};
    k = 3;
    REQUIRE(max_sum_subarray_of_size_k(numbers, k) == 9);

    numbers = {2, 3, 4, 1, 5};
    k = 2;
    REQUIRE(max_sum_subarray_of_size_k(numbers, k) == 7);
}

TEST_CASE("rotate_elements() tests", "[rotate_elements() tests]")
{
    std::vector<int> numbers;
    std::vector<int> result;
    size_t k;

    numbers = {1, 2, 3, 4, 5};
    k = 2;
    result = {4, 5, 1, 2, 3};
    rotate_elements(numbers, k);

    REQUIRE(numbers == result);

    numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    k = 5;
    result = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    rotate_elements(numbers, k);

    REQUIRE(numbers == result);

    numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    k = 3;
    result = {9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8};
    rotate_elements(numbers, k);

    REQUIRE(numbers == result);

    numbers = {1, 2, 3, 4, 5};
    k = 5;
    result = {1, 2, 3, 4, 5};
    rotate_elements(numbers, k);

    REQUIRE(numbers == result);
}

TEST_CASE("replace_array_with_right_side_sum() tests", "[replace_array_with_right_side_sum() tests]")
{
    std::vector<int> numbers;
    std::vector<int> result;

    numbers = {1, 2, 5, 2, 2, 5};
    result = {16, 14, 9, 7, 5, 0};
    replace_array_with_right_side_sum(numbers);

    REQUIRE(numbers == result);

    numbers = {5, 1, 3, 2, 4};
    result = {10, 9, 6, 4, 0};
    replace_array_with_right_side_sum(numbers);

    REQUIRE(numbers == result);
}

TEST_CASE("find_pair_with_given_sum_add_memory() tests", "[array]")
{
    std::vector<int> numbers;
    int sum;

    numbers = {8, 7, 2, 5, 3, 1};
    sum = 10;
    REQUIRE(find_pair_with_given_sum(numbers, sum) == 4);

    numbers = {8, 7, 2, 5, 3, 1};
    sum = 15;
    REQUIRE(find_pair_with_given_sum(numbers, sum) == 2);

    numbers = {8, 7, 2, 5, 3, 1};
    sum = 16;
    REQUIRE(find_pair_with_given_sum(numbers, sum) == 0);

    numbers = {8, 7, 2, 5, 3, 1, 8};
    sum = 16;
    REQUIRE(find_pair_with_given_sum(numbers, sum) == 2);

    numbers = {8, 7, 2, 5, 3, 1, 8, 8};
    sum = 16;
    REQUIRE(find_pair_with_given_sum(numbers, sum) == 3);
}

TEST_CASE("get_subarrays_with_sum_0() tests", "[array]")
{
    std::vector<int> numbers;
    std::vector<std::pair<unsigned int, unsigned int>> result;
    std::vector<std::pair<unsigned int, unsigned int>> tmp;

    numbers = {4, 2, -3, -1, 0, 4};
    result = {{2, 5}, {4, 4}};

    tmp = get_subarrays_with_sum_0(numbers);
    std::sort(tmp.begin(), tmp.end());
    REQUIRE(tmp == result);

    numbers = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    result = {{0, 2}, {0, 9}, {1, 3}, {2, 5}, {3, 9}, {5, 7}};

    tmp = get_subarrays_with_sum_0(numbers);
    std::sort(tmp.begin(), tmp.end());
    REQUIRE(tmp == result);
}

TEST_CASE("find_the_one_duplicate() tests", "[array]")
{
    std::vector<int> numbers;

    numbers = {1, 2, 3, 4, 4};
    REQUIRE(find_the_one_duplicate(numbers) == 4);

    numbers = {1, 2, 3, 4, 2};
    REQUIRE(find_the_one_duplicate(numbers) == 2);

    numbers = {5, 3, 1, 2, 4, 2, 6};
    REQUIRE(find_the_one_duplicate(numbers) == 2);

    numbers = {5, 3, 1, 2, 3, 4, 6};
    REQUIRE(find_the_one_duplicate(numbers) == 3);
}

TEST_CASE("largest_subarray_with_consecutive_ints() tests", "[array]")
{
    std::vector<int> numbers;

    numbers = {2, 0, 2, 1, 4, 3, 1, 0};
    REQUIRE(largest_subarray_with_consecutive_ints(numbers) == 5);

    numbers = {7, 3, 1, 2, 5, 6, 10};
    REQUIRE(largest_subarray_with_consecutive_ints(numbers) == 3);

    numbers = {5, 3, 15, 11, 10, 8, 12, 9, 15};
    REQUIRE(largest_subarray_with_consecutive_ints(numbers) == 5);

    numbers = {5, 5, 5, 5, 5, 5, 5, 5};
    REQUIRE(largest_subarray_with_consecutive_ints(numbers) == 1);
}

TEST_CASE("max_len_subarray_having_sum_k() tests", "[array]")
{
   std::vector<int> numbers;

   numbers = {5, 6, -5, 5, 3, 5, 3, -2, 0};
   REQUIRE(max_len_subarray_having_sum_k(numbers, 8) == 4);

   numbers = {10, 5, 2, 7, 1, 9};
   REQUIRE(max_len_subarray_having_sum_k(numbers, 15) == 4);

    numbers = {-5, 8, -14, 2, 4, 12};
    REQUIRE(max_len_subarray_having_sum_k(numbers, -5) == 5);

    numbers = {5, 5, 5, 5, 5, 5, 5};
    REQUIRE(max_len_subarray_having_sum_k(numbers, 5) == 1);
}

TEST_CASE("max_len_subarray_having_equal_0s_and_1s() tests", "[array]")
{
    std::vector<unsigned int> numbers;

    numbers = {0, 0, 1, 0, 1, 0, 0};
    REQUIRE(max_len_subarray_having_equal_0s_and_1s(numbers) == 4);

    numbers = {1, 0, 1, 1, 1, 0, 0};
    REQUIRE(max_len_subarray_having_equal_0s_and_1s(numbers) == 6);

    numbers = {0, 0, 1, 1, 0};
    REQUIRE(max_len_subarray_having_equal_0s_and_1s(numbers) == 4);
}

TEST_CASE("move_all_zeros_to_end() tests", "[array]")
{
    std::vector<int> numbers;
    std::vector<int> result;

    numbers = {6, 0, 8, 2, 3, 0, 4, 0, 1};
    result = {6, 8, 2, 3, 4, 1, 0, 0, 0};
    move_all_zeros_to_end(numbers);
    REQUIRE(numbers == result);

    numbers = {8, 3, 0, 0, 0, 0};
    result = {8, 3, 0, 0, 0, 0};
    move_all_zeros_to_end(numbers);
    REQUIRE(numbers == result);

    numbers = {8, 0, 0, 0, 0, 3};
    result = {8, 3, 0, 0, 0, 0};
    move_all_zeros_to_end(numbers);
    REQUIRE(numbers == result);

    numbers = {0, 0, 0, 6, 0, 8, 2, 0, 0, 3, 0, 0, 4, 0, 1, 0, 2, 0, 5};
    result = {6, 8, 2, 3, 4, 1, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    move_all_zeros_to_end(numbers);
    REQUIRE(numbers == result);
}

TEST_CASE("merge_to_partially_filled_array() tests", "[array]")
{
    std::vector<int> partial;
    std::vector<int> rest;
    std::vector<int> result;

    partial = {0, 2, 0, 3, 0, 5, 6, 0, 0};
    rest = {1, 8, 9, 10, 15};
    result = {1, 2, 3, 5, 6, 8, 9, 10, 15};

    merge_to_partially_filled_array(partial, rest);
    REQUIRE(partial == result);

    partial = {0, 0, 0, 0, 0};
    rest = {1, 8, 9, 10, 15};
    result = {1, 8, 9, 10, 15};

    merge_to_partially_filled_array(partial, rest);
    REQUIRE(partial == result);

    partial = {1, 2, 3, 4, 5};
    rest = {};
    result = {1, 2, 3, 4, 5};

    merge_to_partially_filled_array(partial, rest);
    REQUIRE(partial == result);
}

TEST_CASE("max_product_with_two_elements() tests", "[array]")
{
    std::vector<int> numbers;

    numbers = {-10, -3, 5, 6, -2};
    REQUIRE(max_product_with_two_elements(numbers) == 30);

    numbers = {-3, 8, 10, -10, 20, 0, 25, 25, -8};
    REQUIRE(max_product_with_two_elements(numbers) == 625);

    numbers = {-10, -3, 5, 6, -2, 6};
    REQUIRE(max_product_with_two_elements(numbers) == 36);

    numbers = {-10, -3, 5, 6, -2, 6, -10};
    REQUIRE(max_product_with_two_elements(numbers) == 100);
}

TEST_CASE("get_index_to_replace_to_maximize_1s() tests", "[array]")
{
    std::vector<unsigned short> numbers;

    numbers = {0, 0, 1, 0, 1, 1, 1, 0, 1, 1};
    REQUIRE(get_index_to_replace_to_maximize_1s(numbers) == 7);

    numbers = {0, 0, 1, 0, 1, 1, 0, 0, 1, 1};
    REQUIRE(get_index_to_replace_to_maximize_1s(numbers) == 3);

    numbers = {0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    REQUIRE(get_index_to_replace_to_maximize_1s(numbers) == 3);
}

TEST_CASE("next_greater_element() tests", "[array][nge]")
{
    std::vector<int> elements;
    std::vector<int> result;

    elements = {2, 1, 2, 4, 3};
    result = {4, 2, 4, -1, -1};

    REQUIRE(next_greater_element(elements) == result);

    elements = {4, 5, 2, 25};
    result = {5, 25, 25, -1};

    REQUIRE(next_greater_element(elements) == result);

    elements = {13, 7, 6, 12};
    result = {-1, 12, 12, -1};

    REQUIRE(next_greater_element(elements) == result);
}

TEST_CASE("next_higher_temperature() tests", "[array][nht]")
{
    std::vector<int> temps;
    std::vector<int> result;

    temps = {73, 74, 75, 71, 69, 72, 76, 73};
    result = {1, 1, 4, 2, 1, 1, -1, -1};

    REQUIRE(next_higher_temperature(temps) == result);
}
