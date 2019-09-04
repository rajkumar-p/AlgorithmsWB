#include "catch.hpp"
#include "searching_algorithms.hpp"

TEST_CASE("binary_search() tests", "[binary_search() tests]")
{
    std::vector<int> i_elements;

    int pos;

    i_elements = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };

    pos = binary_search(i_elements, 23);
    REQUIRE(pos == 5);

    pos = binary_search(i_elements, 72);
    REQUIRE(pos == 8);

    pos = binary_search(i_elements, 2);
    REQUIRE(pos == 0);

    pos = binary_search(i_elements, 91);
    REQUIRE(pos == 9);

    pos = binary_search(i_elements, 8);
    REQUIRE(pos == 2);

    pos = binary_search(i_elements, 5);
    REQUIRE(pos == 1);

    pos = binary_search(i_elements, 16);
    REQUIRE(pos == 4);

    pos = binary_search(i_elements, 22);
    REQUIRE(pos == -1);

    pos = binary_search(i_elements, 24);
    REQUIRE(pos == -1);

    pos = binary_search(i_elements, 100);
    REQUIRE(pos == -1);

    pos = binary_search(i_elements, -1);
    REQUIRE(pos == -1);

    i_elements = { 1, 3, 4, 6, 7, 8, 10, 13, 14, 18, 19, 21, 24, 37, 40, 45, 71 };

    pos = binary_search(i_elements, 7);
    REQUIRE(pos == 4);

    pos = binary_search(i_elements, 8);
    REQUIRE(pos == 5);

    pos = binary_search(i_elements, 24);
    REQUIRE(pos == 12);

    pos = binary_search(i_elements, 90);
    REQUIRE(pos == -1);

    pos = binary_search(i_elements, 0);
    REQUIRE(pos == -1);
}

TEST_CASE("binary_search_leftmost() tests", "[binary_search_leftmost() tests]")
{
    std::vector<int> i_elements;

    int pos;

    i_elements = { 1, 2, 3, 4, 4, 5, 6, 7 };

    pos = binary_search_leftmost(i_elements, 4);
    REQUIRE(pos == 3);

    pos = binary_search_leftmost(i_elements, 5);
    REQUIRE(pos == 5);

    pos = binary_search_leftmost(i_elements, 6);
    REQUIRE(pos == 6);

    pos = binary_search_leftmost(i_elements, 7);
    REQUIRE(pos == 7);

    pos = binary_search_leftmost(i_elements, 9);
    REQUIRE(pos == -1);

    i_elements = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5 };

    pos = binary_search_leftmost(i_elements, 1);
    REQUIRE(pos == 0);

    pos = binary_search_leftmost(i_elements, 2);
    REQUIRE(pos == 4);

    pos = binary_search_leftmost(i_elements, 3);
    REQUIRE(pos == 8);

    pos = binary_search_leftmost(i_elements, 4);
    REQUIRE(pos == 12);

    pos = binary_search_leftmost(i_elements, 5);
    REQUIRE(pos == 16);

    pos = binary_search_leftmost(i_elements, 6);
    REQUIRE(pos == -1);

    i_elements = { 1, 3, 4, 6, 7, 8, 10, 13, 14, 18, 19, 21, 24, 37, 40, 45, 71 };

    pos = binary_search_leftmost(i_elements, 7);
    REQUIRE(pos == 4);

    pos = binary_search_leftmost(i_elements, 8);
    REQUIRE(pos == 5);

    pos = binary_search_leftmost(i_elements, 24);
    REQUIRE(pos == 12);

    pos = binary_search_leftmost(i_elements, 90);
    REQUIRE(pos == -1);

    pos = binary_search_leftmost(i_elements, 0);
    REQUIRE(pos == -1);
}
