#include <iostream>
#include "dp_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Hello World!!!"
        << std::endl;
    std::string str;
    str = "GEEKSFORGEEKS";
    size_t s = longest_substr_with_unique_chars(str);
    return 0;
}