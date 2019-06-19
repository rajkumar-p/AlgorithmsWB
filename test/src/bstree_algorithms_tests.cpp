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

TEST_CASE("level_order() tests", "[bst_to_gst() tests]")
{
    std::shared_ptr<BSTree<int>> bstree(
            std::make_shared<BSTree<int>>(4));
    bstree->insert({1, 6, 0, 2, 5, 7, 3, 8});

    std::vector<std::vector<int>> check;
    std::vector<std::vector<int>> result;

    check = {{4}, {1, 6}, {0, 2, 5, 7}, {3, 8}};
    result = level_order(bstree);

    REQUIRE(result == check);

    bstree.reset();

    bstree = std::make_shared<BSTree<int>>(15);
    bstree->insert({5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22});

    check = {{15}, {5, 16}, {3, 12, 20}, {10, 13, 18, 23}, {6, 21}, {7, 22}};
    result = level_order(bstree);

    REQUIRE(result == check);
}

TEST_CASE("level_order_reverse() tests", "[bst_to_gst_reverse() tests]")
{
    std::shared_ptr<BSTree<int>> bstree(
            std::make_shared<BSTree<int>>(4));
    bstree->insert({1, 6, 0, 2, 5, 7, 3, 8});

    std::vector<std::vector<int>> check;
    std::vector<std::vector<int>> result;

    check = {{4}, {1, 6}, {0, 2, 5, 7}, {3, 8}};
    std::reverse(check.begin(), check.end());
    result = level_order_reverse(bstree);

    REQUIRE(result == check);

    bstree.reset();

    bstree = std::make_shared<BSTree<int>>(15);
    bstree->insert({5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22});

    check = {{15}, {5, 16}, {3, 12, 20}, {10, 13, 18, 23}, {6, 21}, {7, 22}};
    std::reverse(check.begin(), check.end());
    result = level_order_reverse(bstree);

    REQUIRE(result == check);
}

TEST_CASE("zig_zag_level_order() tests", "[zig_zag_level_order() tests]")
{
    std::shared_ptr<BSTree<int>> bstree(
            std::make_shared<BSTree<int>>(4));
    bstree->insert({1, 6, 0, 2, 5, 7, 3, 8});

    std::vector<std::vector<int>> check;
    std::vector<std::vector<int>> result;

    check = {{4}, {6, 1}, {0, 2, 5, 7}, {8, 3}};
    result = zigzag_level_order(bstree);

    REQUIRE(result == check);

    bstree.reset();

    bstree = std::make_shared<BSTree<int>>(15);
    bstree->insert({5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22});

    check = {{15}, {16, 5}, {3, 12, 20}, {23, 18, 13, 10}, {6, 21}, {22, 7}};
    result = zigzag_level_order(bstree);

    REQUIRE(result == check);
}
