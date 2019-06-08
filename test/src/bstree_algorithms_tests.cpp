#include "catch.hpp"
#include "bstree_algorithms.hpp"

TEST_CASE("bst_to_gst() tests", "[bst_to_gst() tests]")
{
    std::shared_ptr<BSTree<int>> bstree(
            std::make_shared<BSTree<int>>(4));
    bstree->insert({1, 6, 0, 2, 5, 7, 3, 8});

    bst_to_gst(bstree);

    std::vector<int> result;
    std::vector<int> check;

    check = {36, 36, 35, 33, 30, 26, 21, 15, 8};
    bstree->inorder(bstree->root(),
                    [&result](std::shared_ptr<BSTreeNode<int>> node) {
                        result.push_back(node->data());
    });

    REQUIRE(result == check);

    bstree.reset();

    bstree = std::make_shared<BSTree<int>>(15);
    bstree->insert({5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22});

    bst_to_gst(bstree);

    check = {191, 188, 183, 177, 170, 160, 148, 135, 120, 104, 86, 66, 45, 23};
    result.clear();
    bstree->inorder(bstree->root(),
                    [&result](std::shared_ptr<BSTreeNode<int>> node) {
                        result.push_back(node->data());
                    });

    REQUIRE(result == check);
}
