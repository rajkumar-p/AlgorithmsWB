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

    numbers = {2, 1, 5, 2, 3, 2};
    insertion_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
            std::greater<int>()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    insertion_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
            std::greater<int>()) == true);

    std::vector<std::string> words;
    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    insertion_sort(words);

    REQUIRE(std::is_sorted(words.begin(), words.end()) == true);

    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    insertion_sort(words, std::greater<std::string>());

    REQUIRE(std::is_sorted(words.begin(), words.end(),
            std::greater<std::string>()) == true);
}

TEST_CASE("selection_sort() tests", "[selection_sort() tests]")
{
    std::vector<int> numbers;
    numbers = {2, 1, 5, 2, 3, 2};
    selection_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    selection_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {2, 1, 5, 2, 3, 2};
    selection_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    selection_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()) == true);

    std::vector<std::string> words;
    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    selection_sort(words);

    REQUIRE(std::is_sorted(words.begin(), words.end()) == true);

    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    selection_sort(words, std::greater<std::string>());

    REQUIRE(std::is_sorted(words.begin(), words.end(),
                           std::greater<std::string>()) == true);
}

TEST_CASE("bubble_sort() tests", "[bubble_sort() tests]")
{
    std::vector<int> numbers;
    numbers = {2, 1, 5, 2, 3, 2};
    bubble_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {2, 1, 5, 2, 3, 2};
    bubble_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()) == true);

    std::vector<std::string> words;
    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    bubble_sort(words);

    REQUIRE(std::is_sorted(words.begin(), words.end()) == true);

    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    bubble_sort(words, std::greater<std::string>());

    REQUIRE(std::is_sorted(words.begin(), words.end(),
                           std::greater<std::string>()) == true);
}

TEST_CASE("merge_sort() tests", "[merge_sort() tests]")
{
    std::vector<int> numbers;
    numbers = {2, 1, 5, 2, 3, 2};
    merge_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {2, 1, 5, 2, 3, 2};
    merge_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()) == true);

    std::vector<std::string> words;
    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    merge_sort(words);

    REQUIRE(std::is_sorted(words.begin(), words.end()) == true);

    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    merge_sort(words, std::greater<std::string>());

    REQUIRE(std::is_sorted(words.begin(), words.end(),
                           std::greater<std::string>()) == true);
}
