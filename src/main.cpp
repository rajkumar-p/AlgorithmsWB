#include <iostream>
#include <vector>
#include "bstree.hpp"
#include "bstree_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Hello World!!!"
        << std::endl;

    std::shared_ptr<BSTree<int>> bstree(
            std::make_shared<BSTree<int>>(15));
    bstree->insert({5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22});

    std::vector<std::vector<int>> output = zigzag_level_order(bstree);
    for (auto vecs : output) {
        for (auto v : vecs) {
            std::cout << v <<"\t";
        }
        std::cout << std::endl;
    }


    return 0;
}