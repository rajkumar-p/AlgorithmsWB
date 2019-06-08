#include "catch.hpp"
#include "bstree.hpp"

TEST_CASE("insert() tests", "[insert() tests]")
{
    std::shared_ptr<BSTree<unsigned int>> bstree(
            std::make_shared<BSTree<unsigned int>>(15));

    bstree->insert(5);
    bstree->insert(16);
    bstree->insert({3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22});

    REQUIRE(bstree->root()->data() == 15);
    REQUIRE(bstree->root()->count() == 1);

    std::shared_ptr<BSTreeNode<unsigned int>> root_left = nullptr;
    std::shared_ptr<BSTreeNode<unsigned int>> root_right = nullptr;
    root_left = bstree->root()->_left;
    root_right = bstree->root()->_right;

    REQUIRE(root_left->data() == 5);
    REQUIRE(root_left->count() == 1);

    REQUIRE(root_right->data() == 16);
    REQUIRE(root_right->count() == 1);

    std::vector<unsigned int> sorted;
    bstree->inorder(bstree->root(),
            [&sorted](std::shared_ptr<BSTreeNode<unsigned int>> node) {
                sorted.push_back(node->data());
    });

    REQUIRE(std::is_sorted(sorted.begin(), sorted.end(), std::less<unsigned int>()));
}

TEST_CASE("find() tests", "[find() tests]")
{
    std::shared_ptr<BSTree<unsigned int>> bstree(
            std::make_shared<BSTree<unsigned int>>(15));
    bstree->insert({5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22});

    std::shared_ptr<BSTreeNode<unsigned int>> node_to_find = nullptr;

    node_to_find = bstree->find(18);
    REQUIRE(node_to_find->data() == 18);
    REQUIRE(node_to_find->count() == 1);
    REQUIRE(node_to_find->_left == nullptr);
    REQUIRE(node_to_find->_right == nullptr);

    node_to_find = bstree->find(12);
    REQUIRE(node_to_find->data() == 12);
    REQUIRE(node_to_find->count() == 1);
    REQUIRE(node_to_find->_left->data() == 10);
    REQUIRE(node_to_find->_right->data() == 13);

    node_to_find = bstree->find(122);
    REQUIRE(node_to_find == nullptr);
}

TEST_CASE("find_parent() tests", "[find_parent() tests]")
{
    std::shared_ptr<BSTree<unsigned int>> bstree(
            std::make_shared<BSTree<unsigned int>>(15));
    bstree->insert({5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22});

    std::shared_ptr<BSTreeNode<unsigned int>> parent = nullptr;

    parent = bstree->find_parent_of(bstree->find(18));
    REQUIRE(parent->data() == 20);
    REQUIRE(parent->count() == 1);

    parent = bstree->find_parent_of(parent);
    REQUIRE(parent->data() == 16);
    REQUIRE(parent->count() == 1);

    parent = bstree->find_parent_of(bstree->find(15));
    REQUIRE(parent == nullptr);

    parent = bstree->find_parent_of(bstree->find(155));
    REQUIRE(parent == nullptr);
}
