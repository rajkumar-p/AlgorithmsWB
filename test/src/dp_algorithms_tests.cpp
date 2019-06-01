#include "catch.hpp"
#include "dp_algorithms.hpp"

TEST_CASE("smallest_subarray_with_sum_greater_than_x() tests", "smallest_subarray_with_sum_greater_than_x() tests]")
{
    SECTION("smallest_subarray_with_sum_greater_than_x() tests") {
        std::vector<unsigned int> numbers;
        unsigned int x;

        numbers = {1, 4, 45, 6, 0, 19};
        x = 51;

        REQUIRE(smallest_subarray_with_sum_greater_than_x(numbers, x) == 3);

        numbers = {1, 10, 5, 2, 7};
        x = 9;

        REQUIRE(smallest_subarray_with_sum_greater_than_x(numbers, x) == 1);

        numbers = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
        x = 280;

        REQUIRE(smallest_subarray_with_sum_greater_than_x(numbers, x) == 4);
    }
}
