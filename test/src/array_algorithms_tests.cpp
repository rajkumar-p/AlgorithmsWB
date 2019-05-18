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
