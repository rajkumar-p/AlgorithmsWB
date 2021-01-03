#include "catch.hpp"
#include "searching_algorithms.hpp"

TEST_CASE("binary_search() tests", "[search][binary_search]")
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

    i_elements = {1};

    pos = binary_search(i_elements, 1);
    REQUIRE(pos == 0);

    pos = binary_search(i_elements, 5);
    REQUIRE(pos == -1);

    pos = binary_search(i_elements, 0);
    REQUIRE(pos == -1);
}

TEST_CASE("binary_search_leftmost() tests", "[search][binary_search][binary_search_left]")
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

    i_elements = {1};

    pos = binary_search_leftmost(i_elements, 1);
    REQUIRE(pos == 0);

    pos = binary_search_leftmost(i_elements, 5);
    REQUIRE(pos == -1);

    pos = binary_search_leftmost(i_elements, 0);
    REQUIRE(pos == -1);

    i_elements = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    pos = binary_search_leftmost(i_elements, 1);
    REQUIRE(pos == 0);

    pos = binary_search_leftmost(i_elements, 5);
    REQUIRE(pos == -1);

    pos = binary_search_leftmost(i_elements, 0);
    REQUIRE(pos == -1);
}

TEST_CASE("binary_search_rightmost() tests", "[search][binary_search][binary_search_right]")
{
    std::vector<int> i_elements;

    int pos;

    i_elements = { 1, 2, 3, 4, 4, 5, 6, 7 };

    pos = binary_search_rightmost(i_elements, 4);
    REQUIRE(pos == 4);

    pos = binary_search_rightmost(i_elements, 5);
    REQUIRE(pos == 5);

    pos = binary_search_rightmost(i_elements, 6);
    REQUIRE(pos == 6);

    pos = binary_search_rightmost(i_elements, 7);
    REQUIRE(pos == 7);

    pos = binary_search_rightmost(i_elements, 9);
    REQUIRE(pos == -1);

    i_elements = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5 };

    pos = binary_search_rightmost(i_elements, 1);
    REQUIRE(pos == 3);

    pos = binary_search_rightmost(i_elements, 2);
    REQUIRE(pos == 7);

    pos = binary_search_rightmost(i_elements, 3);
    REQUIRE(pos == 11);

    pos = binary_search_rightmost(i_elements, 4);
    REQUIRE(pos == 15);

    pos = binary_search_rightmost(i_elements, 5);
    REQUIRE(pos == 18);

    pos = binary_search_rightmost(i_elements, 6);
    REQUIRE(pos == -1);

    i_elements = { 1, 3, 4, 6, 7, 8, 10, 13, 14, 18, 19, 21, 24, 37, 40, 45, 71 };

    pos = binary_search_rightmost(i_elements, 7);
    REQUIRE(pos == 4);

    pos = binary_search_rightmost(i_elements, 8);
    REQUIRE(pos == 5);

    pos = binary_search_rightmost(i_elements, 24);
    REQUIRE(pos == 12);

    pos = binary_search_rightmost(i_elements, 90);
    REQUIRE(pos == -1);

    pos = binary_search_rightmost(i_elements, 0);
    REQUIRE(pos == -1);

    i_elements = {1};

    pos = binary_search_rightmost(i_elements, 1);
    REQUIRE(pos == 0);

    pos = binary_search_rightmost(i_elements, 5);
    REQUIRE(pos == -1);

    pos = binary_search_rightmost(i_elements, 0);
    REQUIRE(pos == -1);

    i_elements = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    pos = binary_search_rightmost(i_elements, 1);
    REQUIRE(pos == 8);

    pos = binary_search_rightmost(i_elements, 5);
    REQUIRE(pos == -1);

    pos = binary_search_rightmost(i_elements, 0);
    REQUIRE(pos == -1);
}

TEST_CASE("sub_optimal_if_exits_x_and_y_equals_sum() tests", "[sub_optimal_if_exits_x_and_y_equals_sum() tests]")
{
    std::vector<int> elements;

    elements = { 5, 2, 4, 6, 1, 3 };

    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 9) == true);
    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 7) == true);
    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 15) == false);
    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 10) == true);

    elements = { 4, 4, 4, 4, 4 };

    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 8) == true);
    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 16) == false);
    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 15) == false);

    elements = { -1, 7, -5, 2, 0, 3 };

    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 6) == true);
    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 3) == true);
    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, -1) == true);
    REQUIRE(sub_optimal_if_exits_x_and_y_equals_sum(elements, 12) == false);
}

TEST_CASE("if_exits_x_and_y_equals_sum() tests", "[if_exits_x_and_y_equals_sum() tests]")
{
    std::vector<int> elements;

    elements = { 5, 2, 4, 6, 1, 3 };

    REQUIRE(if_exits_x_and_y_equals_sum(elements, 9) == true);
    REQUIRE(if_exits_x_and_y_equals_sum(elements, 7) == true);
    REQUIRE(if_exits_x_and_y_equals_sum(elements, 15) == false);
    REQUIRE(if_exits_x_and_y_equals_sum(elements, 10) == true);

    elements = { 4, 4, 4, 4, 4 };

    REQUIRE(if_exits_x_and_y_equals_sum(elements, 8) == true);
    REQUIRE(if_exits_x_and_y_equals_sum(elements, 16) == false);
    REQUIRE(if_exits_x_and_y_equals_sum(elements, 15) == false);

    elements = { -1, 7, -5, 2, 0, 3 };

    REQUIRE(if_exits_x_and_y_equals_sum(elements, 6) == true);
    REQUIRE(if_exits_x_and_y_equals_sum(elements, 3) == true);
    REQUIRE(if_exits_x_and_y_equals_sum(elements, -1) == true);
    REQUIRE(if_exits_x_and_y_equals_sum(elements, 12) == false);
}
