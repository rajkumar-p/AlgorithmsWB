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

TEST_CASE("longest_substr_with_k_unique_chars() tests", "longest_substr_with_k_unique_chars() tests]")
{
    SECTION("longest_substr_with_k_unique_chars() tests") {
        std::string str;
        unsigned int k;

        str = "araaci";
        k = 2;
        REQUIRE(longest_substr_with_k_unqiue_chars(str, k) == 4);

        str = "aabbcc";
        k = 1;
        REQUIRE(longest_substr_with_k_unqiue_chars(str, k) == 2);

        str = "aabbcc";
        k = 2;
        REQUIRE(longest_substr_with_k_unqiue_chars(str, k) == 4);

        str = "aabbcc";
        k = 3;
        REQUIRE(longest_substr_with_k_unqiue_chars(str, k) == 6);

        str = "aaabbb";
        k = 3;
        REQUIRE(longest_substr_with_k_unqiue_chars(str, k) == 6);
    }
}
