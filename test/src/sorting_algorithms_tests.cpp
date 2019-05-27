#include "catch.hpp"
#include "sorting_algorithms.hpp"

TEST_CASE("insertion_sort() tests", "[insertion_sort() tests]")
{
    std::vector<int> numbers;
    numbers = {2, 1, 5, 2, 3, 2};
    insertion_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    insertion_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    std::vector<std::string> words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    insertion_sort(words);

    REQUIRE(std::is_sorted(words.begin(), words.end()) == true);
}
