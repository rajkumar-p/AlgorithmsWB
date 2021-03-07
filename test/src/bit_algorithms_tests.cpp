#include "catch.hpp"
#include "bit_algorithms.h"

TEST_CASE("count_ones() tests", "[bits]")
{
    REQUIRE(count_ones(0) == 0);
    REQUIRE(count_ones(8) == 1);
    REQUIRE(count_ones(9) == 2);
    REQUIRE(count_ones(255) == 8);
    REQUIRE(count_ones(65535) == 16);
    REQUIRE(count_ones(4294967295) == 32);
}

TEST_CASE("count_ones_by_lookup() tests", "[bits]")
{
    REQUIRE(count_ones_by_lookup(0) == 0);
    REQUIRE(count_ones_by_lookup(8) == 1);
    REQUIRE(count_ones_by_lookup(9) == 2);
    REQUIRE(count_ones_by_lookup(255) == 8);
    REQUIRE(count_ones_by_lookup(65535) == 16);
    REQUIRE(count_ones_by_lookup(4294967295) == 32);
}

TEST_CASE("count_ones_better() tests", "[bits]")
{
    REQUIRE(count_ones_better(0) == 0);
    REQUIRE(count_ones_better(8) == 1);
    REQUIRE(count_ones_better(9) == 2);
    REQUIRE(count_ones_better(255) == 8);
    REQUIRE(count_ones_better(65535) == 16);
    REQUIRE(count_ones_better(4294967295) == 32);
}

TEST_CASE("bit_parity() tests", "[bits]")
{
    REQUIRE(bit_parity(72751076) == 1);
    REQUIRE(bit_parity(637990265) == 0);
    REQUIRE(bit_parity(2005566936) == 0);
    REQUIRE(bit_parity(609176674) == 1);
    REQUIRE(bit_parity(1573007862) == 1);
    REQUIRE(bit_parity(1272193067) == 1);
    REQUIRE(bit_parity(2520907817) == 1);
    REQUIRE(bit_parity(3482053608) == 0);
    REQUIRE(bit_parity(589824541) == 0);
    REQUIRE(bit_parity(3881954689) == 1);
}

TEST_CASE("convert_byte_order() tests", "[bits][cbo]")
{
    int num;
    int result;

    num = 47;
    result = convert_byte_order(num);
    REQUIRE(result == 788529152);

    num = 88888;
    result = convert_byte_order(num);
    REQUIRE(result == 945488128);

    num = -7;
    result = convert_byte_order(num);
    REQUIRE(result == -100663297);

    num = 0;
    result = convert_byte_order(num);
    REQUIRE(result == 0);
}

