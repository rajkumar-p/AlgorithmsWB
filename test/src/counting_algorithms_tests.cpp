#include "catch.hpp"
#include "counting_algorithms.hpp"

TEST_CASE("count_inversions() tests", "[count_inversions() tests]")
{
    std::vector<int> elements;

    elements = { 3, 41, 52, 26, 38, 57, 9, 49 };
    REQUIRE(count_inversions(elements) == 11);

    elements = { 2, 4, 1, 3, 5 };
    REQUIRE(count_inversions(elements) == 3);

    elements = { 8, 4, 2, 1 };
    REQUIRE(count_inversions(elements) == 6);

    elements = { 2, 3, 8, 6, 1 };
    REQUIRE(count_inversions(elements) == 5);

    elements = { 1, 5, 6, 4, 20 };
    REQUIRE(count_inversions(elements) == 2);
}
