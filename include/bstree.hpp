#ifndef ALGORITHMSWORKBENCH_BSTREE_HPP
#define ALGORITHMSWORKBENCH_BSTREE_HPP

#include "bstree_node.hpp"
#include <functional>

template<typename T>
class BSTree {
private:
    std::shared_ptr<BSTreeNode<T>> _root;

public:
    BSTree(std::shared_ptr<BSTreeNode<T>> root);
    BSTree(T root_element);

    std::shared_ptr<BSTreeNode<T>> root();

    void add_node(
            std::shared_ptr<BSTreeNode<T>> node);
    std::shared_ptr<BSTreeNode<T>> add_element(T element);
    std::shared_ptr<BSTreeNode<T>> add_element_iterative(
            std::shared_ptr<BSTreeNode<T>> root, T element);

    void inorder_traversal(
            std::shared_ptr<BSTreeNode<T>> node,
            std::function<void(std::shared_ptr<BSTreeNode<T>>)>&
                    run_for_each_node);
};

template<typename T>
BSTree<T>::BSTree(std::shared_ptr<BSTreeNode<T>> root)
    : _root(root)
{
    _root->_left = nullptr;
    _root->_righ = nullptr;
}

template<typename T>
BSTree<T>::BSTree(T root_element)
    : _root(std::make_shared<BSTreeNode<T>>(root_element))
{
    _root->_left = nullptr;
    _root->_right = nullptr;
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::root()
{
    return _root;
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::add_element(T element)
{
    return add_element_iterative(this->root(),
                                 element);
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::add_element_iterative(
        std::shared_ptr<BSTreeNode<T>> root, T element)
{
    std::shared_ptr<BSTreeNode<T>> parent = nullptr;
    std::shared_ptr<BSTreeNode<T>> node = root;
    while(node != nullptr) {
        parent = node;
        if(element == node->data()) {
            node->increment_count();
            return node;
        } else if(element < node->data()) {
            node = node->_left;
        } else {
            node = node->_right;
        }
    }

    std::shared_ptr<BSTreeNode<T>> new_node(
            std::make_shared<BSTreeNode<T>>(element));
    new_node->_left = nullptr;
    new_node->_right = nullptr;

    if (element < parent->data()) {
        parent->_left = new_node;
    } else {
        parent->_right = new_node;
    }

    return new_node;
}

template<typename T>
void BSTree<T>::inorder_traversal(std::shared_ptr<BSTreeNode<T>> node,
                                  std::function<void(std::shared_ptr<BSTreeNode<T>>)> &run_for_each_node)
{
    if (node != nullptr) {
        inorder_traversal(node->_left, run_for_each_node);
        run_for_each_node(node);
        inorder_traversal(node->_right, run_for_each_node);
    }
}

#endif //ALGORITHMSWORKBENCH_BSTREE_HPP
