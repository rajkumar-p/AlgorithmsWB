#include <iostream>
#include "bstree_algorithms.hpp"

template<typename T>
void custom_traversal_rcl(
        std::shared_ptr<BSTreeNode<T>> node,
        const std::function<void(std::shared_ptr<BSTreeNode<T>> node)> &fn)
{
    if (node != nullptr) {
        custom_traversal_rcl(node->_right, fn);
        fn(node);
        custom_traversal_rcl(node->_left, fn);
    }
}

std::shared_ptr<BSTreeNode<int>> bst_to_gst(
        std::shared_ptr<BSTree<int>> bstree)
{
    int accumulator = 0;
    custom_traversal_rcl<int>(bstree->root(),
            [&accumulator](std::shared_ptr<BSTreeNode<int>> node) {
                accumulator += node->data();
                node->set_data(accumulator);
    });

    return bstree->root();
}
