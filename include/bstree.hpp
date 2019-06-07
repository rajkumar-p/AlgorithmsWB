#ifndef ALGORITHMSWORKBENCH_BSTREE_HPP
#define ALGORITHMSWORKBENCH_BSTREE_HPP

#include "bstree_node.hpp"
#include <functional>

template<typename T>
class BSTree {
private:
    std::shared_ptr<BSTreeNode<T>> _root;

    std::shared_ptr<BSTreeNode<T>> insert_iterative(
            std::shared_ptr<BSTreeNode<T>> root, T element);
public:
    BSTree(T root_element);
    BSTree(std::shared_ptr<BSTreeNode<T>> root);

    std::shared_ptr<BSTreeNode<T>> root();

    std::shared_ptr<BSTreeNode<T>> insert(T element);
    std::shared_ptr<BSTreeNode<T>> insert(const std::vector<T> &elements);
    std::shared_ptr<BSTreeNode<T>> insert_at(
            std::shared_ptr<BSTreeNode<T>> root,
            T element);

    std::shared_ptr<BSTreeNode<T>> find(T element);
    std::shared_ptr<BSTreeNode<T>> find_from(
            std::shared_ptr<BSTreeNode<T>> node,
            T element);

    void inorder(
            std::shared_ptr<BSTreeNode<T>> node,
            const std::function<void(std::shared_ptr<BSTreeNode<T>>)> &
            run_for_each_node);
};

template<typename T>
BSTree<T>::BSTree(T root_element)
        : _root(std::make_shared<BSTreeNode<T>>(root_element))
{
    _root->_left = nullptr;
    _root->_right = nullptr;
}

template<typename T>
BSTree<T>::BSTree(std::shared_ptr<BSTreeNode<T>> root)
    : _root(root)
{

}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::root()
{
    return _root;
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::insert(T element)
{
    return insert_iterative(this->root(),
                            element);
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::insert_at(
        std::shared_ptr<BSTreeNode<T>> root, T element)
{
    this->insert_iterative(root, element);
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::insert_iterative(
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
std::shared_ptr<BSTreeNode<T>> BSTree<T>::insert(
        const std::vector<T> &elements)
{
    for (const T &element : elements) {
        this->insert(element);
    }

    return this->root();
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::find(T element)
{
    return this->find_from(this->root(), element);
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::find_from(
        std::shared_ptr<BSTreeNode<T>> node,
        T element)
{
    if (node == nullptr) {
        return nullptr;
    } else if (node->data() == element) {
        return node;
    } else if (node->data() > element) {
        return find_from(node->_left, element);
    } else {
        return find_from(node->_right, element);
    }
}

template<typename T>
void BSTree<T>::inorder(std::shared_ptr<BSTreeNode<T>> node,
                        const std::function<void(std::shared_ptr<BSTreeNode<T>>)> &run_for_each_node)
{
    if (node != nullptr) {
        inorder(node->_left, run_for_each_node);
        run_for_each_node(node);
        inorder(node->_right, run_for_each_node);
    }
}

#endif //ALGORITHMSWORKBENCH_BSTREE_HPP
