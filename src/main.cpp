#include <iostream>
#include <vector>
#include "sorting_algorithms.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Hello world!!!" << std::endl;
    std::vector<int> vec = {2, 1, 5, 2, 3, 2};
    heap_sort(vec, std::greater<int>());
    return 0;
}
