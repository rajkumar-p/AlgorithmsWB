#include "catch.hpp"
#include "numerical_algorithms.hpp"

TEST_CASE("reverse() tests", "[numerical]")
{
    REQUIRE(reverse(4828) == 8284);
    REQUIRE(reverse(0) == 0);
    REQUIRE(reverse(11111111) == 11111111);
    REQUIRE(reverse(8510074) == 4700158);
}
