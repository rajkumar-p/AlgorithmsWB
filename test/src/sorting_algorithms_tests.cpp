#include "catch.hpp"
#include "sorting_algorithms.hpp"
#include "utils.h"

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

TEST_CASE("heap_sort() tests", "[sorting]")
{
    std::vector<int> numbers;
    numbers = {2, 1, 5, 2, 3, 2};
    heap_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    heap_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()) == true);

    numbers = {2, 1, 5, 2, 3, 2};
    heap_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()) == true);

    numbers = {8, 7, 6, 5, 4, 3, 2, 1};
    heap_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()) == true);

    numbers = get_random_numbers<int>(0, 100, 20);
    heap_sort(numbers);

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = get_random_numbers<int>(0, 100, 20);
    heap_sort(numbers, std::greater<int>());

    REQUIRE(std::is_sorted(numbers.begin(), numbers.end(),
                           std::greater<int>()));

    std::vector<float> decs;
    decs = get_random_numbers<float>(0.0, 1.0, 10);
    heap_sort(decs);

    REQUIRE(std::is_sorted(decs.begin(), decs.end()));

    std::vector<std::string> words;
    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    heap_sort(words);

    REQUIRE(std::is_sorted(words.begin(), words.end()) == true);

    words = {"Hello", "Ana", "Zebra", "Alice", "World", "Moon"};
    heap_sort(words, std::greater<std::string>());

    REQUIRE(std::is_sorted(words.begin(), words.end(),
                           std::greater<std::string>()) == true);
}

TEST_CASE("sort_binary_array() tests", "[sort]")
{
    std::vector<bool> numbers;

    numbers = {1, 0, 1, 0, 1, 0, 0, 1};
    sort_binary_array(numbers);

    REQUIRE(is_sorted(numbers.begin(), numbers.end()));

    numbers = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    sort_binary_array(numbers);

    REQUIRE(is_sorted(numbers.begin(), numbers.end()));

    numbers = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    sort_binary_array(numbers);

    REQUIRE(is_sorted(numbers.begin(), numbers.end()));

    numbers = {1, 1, 1, 1, 1, 0, 0, 0, 0, 1};
    sort_binary_array(numbers);

    REQUIRE(is_sorted(numbers.begin(), numbers.end()));
}

TEST_CASE("sort_array_with_0_1_2() tests", "[sort]")
{
    std::vector<unsigned short> numbers;

    numbers = {1, 1, 0, 2, 0, 0, 1, 2, 2, 0, 1};
    sort_array_with_0_1_2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {2, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1};
    sort_array_with_0_1_2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {2, 1, 0, 2, 1, 0, 2, 1, 0, 2, 1, 0};
    sort_array_with_0_1_2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    sort_array_with_0_1_2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    sort_array_with_0_1_2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    sort_array_with_0_1_2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));
}

TEST_CASE("sort_array_with_0_1_2_V2() tests", "[sort]")
{
    std::vector<unsigned short> numbers;

    numbers = {1, 1, 0, 2, 0, 0, 1, 2, 2, 0, 1};
    sort_array_with_0_1_2_V2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {2, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1};
    sort_array_with_0_1_2_V2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {2, 1, 0, 2, 1, 0, 2, 1, 0, 2, 1, 0};
    sort_array_with_0_1_2_V2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    sort_array_with_0_1_2_V2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    sort_array_with_0_1_2_V2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));

    numbers = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    sort_array_with_0_1_2_V2(numbers);
    REQUIRE(std::is_sorted(numbers.begin(), numbers.end()));
}
