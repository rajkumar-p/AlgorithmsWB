#include <queue>
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

std::vector<std::vector<int>> level_order(
        std::shared_ptr<BSTree<int>> bstree)
{
    if (bstree->root() == nullptr) {
        return {};
    }

    std::queue<std::shared_ptr<BSTreeNode<int>>> node_q;

    std::vector<std::shared_ptr<BSTreeNode<int>>> nodes_list;
    nodes_list.push_back(bstree->root());

    std::vector<std::vector<int>> output;
    while (!nodes_list.empty()) {
        std::vector<int> same_level_values;
        for (const std::shared_ptr<BSTreeNode<int>> node : nodes_list) {
            same_level_values.push_back(node->data());
            node_q.push(node);
        }

        nodes_list.clear();
        output.push_back(same_level_values);

        while (!node_q.empty()) {
            std::shared_ptr<BSTreeNode<int>> top = node_q.front();
            node_q.pop();

            if (top->_left != nullptr) {
                nodes_list.push_back(top->_left);
            }
            if (top->_right != nullptr) {
                nodes_list.push_back(top->_right);
            }
        }
    }

    return output;
}

std::vector<std::vector<int>> level_order_reverse(
        std::shared_ptr<BSTree<int>> bstree)
{
    std::vector<std::vector<int>> level_order_reverse =
            level_order(bstree);

    std::reverse(level_order_reverse.begin(), level_order_reverse.end());

    return level_order_reverse;
}

std::vector<std::vector<int>> zigzag_level_order(
        std::shared_ptr<BSTree<int>> bstree)
{
    if (bstree->root() == nullptr) {
        return {};
    }

    std::deque<std::shared_ptr<BSTreeNode<int>>> node_q;

    std::vector<std::shared_ptr<BSTreeNode<int>>> nodes_list;
    nodes_list.push_back(bstree->root());

    bool zig_zag = true;
    std::vector<std::vector<int>> output;
    while (!nodes_list.empty()) {
        std::vector<int> same_level_values;
        for (const std::shared_ptr<BSTreeNode<int>> node : nodes_list) {
            same_level_values.push_back(node->data());
            node_q.push_back(node);
        }

        nodes_list.clear();
        output.push_back(same_level_values);

        while (!node_q.empty()) {
            std::shared_ptr<BSTreeNode<int>> top = nullptr;
            if (zig_zag) {
                top = node_q.back();
                node_q.pop_back();
            } else {
                top = node_q.front();
                node_q.pop_front();
            }

            if (top->_left != nullptr) {
                nodes_list.push_back(top->_left);
            }
            if (top->_right != nullptr) {
                nodes_list.push_back(top->_right);
            }
        }

        zig_zag = !zig_zag;
    }

    return output;
}
