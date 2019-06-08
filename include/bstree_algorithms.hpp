#ifndef ALGORITHMSWORKBENCH_BSTREE_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_BSTREE_ALGORITHMS_HPP

#include "bstree.hpp"

// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
std::shared_ptr<BSTreeNode<int>> bst_to_gst(
        std::shared_ptr<BSTree<int>> bstree);

#endif //ALGORITHMSWORKBENCH_BSTREE_ALGORITHMS_HPP
