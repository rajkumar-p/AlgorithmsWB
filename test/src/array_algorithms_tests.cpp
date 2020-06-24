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
