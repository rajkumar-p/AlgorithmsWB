#include "catch.hpp"
#include "numerical_algorithms.hpp"

TEST_CASE("reverse() tests", "[numerical]")
{
    REQUIRE(reverse(4828) == 8284);
    REQUIRE(reverse(0) == 0);
    REQUIRE(reverse(11111111) == 11111111);
    REQUIRE(reverse(8510074) == 4700158);
}

TEST_CASE("is_number_a_palindrome() tests", "[numerical]")
{
    REQUIRE(is_number_a_palindrome(40904) == true);
    REQUIRE(is_number_a_palindrome(409504) == false);
    REQUIRE(is_number_a_palindrome(0) == true);
    REQUIRE(is_number_a_palindrome(409904) == true);
}
