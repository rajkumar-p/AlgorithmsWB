#ifndef ALGORITHMSWORKBENCH_BSTREE_HPP
#define ALGORITHMSWORKBENCH_BSTREE_HPP

#include "bstree_node.hpp"
#include <functional>

template<typename T>
class BSTree {
private:
    std::shared_ptr<BSTreeNode<T>> _root;

    std::shared_ptr<BSTreeNode<T>> insert_iterative(
            T element,
            std::shared_ptr<BSTreeNode<T>> root);

    std::shared_ptr<BSTreeNode<T>> find_parent(
            std::shared_ptr<BSTreeNode<T>> parent,
            std::shared_ptr<BSTreeNode<T>> node,
            std::shared_ptr<BSTreeNode<T>> start);

public:
    BSTree(T root_element);
    BSTree(std::shared_ptr<BSTreeNode<T>> root);

    std::shared_ptr<BSTreeNode<T>> root();

    std::shared_ptr<BSTreeNode<T>> insert(T element);
    std::shared_ptr<BSTreeNode<T>> insert(const std::vector<T> &elements);
    std::shared_ptr<BSTreeNode<T>> insert(T element,
            std::shared_ptr<BSTreeNode<T>> start);

    std::shared_ptr<BSTreeNode<T>> find(T element);
    std::shared_ptr<BSTreeNode<T>> find(T element,
            std::shared_ptr<BSTreeNode<T>> start);

    std::shared_ptr<BSTreeNode<T>> find_parent_of(
            std::shared_ptr<BSTreeNode<T>> node);
    std::shared_ptr<BSTreeNode<T>> find_parent_of(
            std::shared_ptr<BSTreeNode<T>> node,
            std::shared_ptr<BSTreeNode<T>> start);

    void remove(T element);

    void inorder(
            std::shared_ptr<BSTreeNode<T>> start,
            const std::function<void(std::shared_ptr<BSTreeNode<T>>)> &
            run_for_each_node);
    void preorder(
            std::shared_ptr<BSTreeNode<T>> start,
            const std::function<void(std::shared_ptr<BSTreeNode<T>>)> &
            run_for_each_node);
    void postorder(
            std::shared_ptr<BSTreeNode<T>> start,
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
    return insert_iterative(element,
            this->root());
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::insert(
        T element,
        std::shared_ptr<BSTreeNode<T>> root)
{
    this->insert_iterative(element, root);
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::insert_iterative(
        T element,
        std::shared_ptr<BSTreeNode<T>> root)
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
    return this->find(element, this->root());
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::find(T element,
        std::shared_ptr<BSTreeNode<T>> start)
{
    if (start == nullptr) {
        return nullptr;
    } else if (start->data() == element) {
        return start;
    } else if (start->data() > element) {
        return find(element, start->_left);
    } else {
        return find(element, start->_right);
    }
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::find_parent_of(
        std::shared_ptr<BSTreeNode<T>> node)
{
    return this->find_parent_of(node, this->root());
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::find_parent_of(
        std::shared_ptr<BSTreeNode<T>> node,
        std::shared_ptr<BSTreeNode<T>> start)
{
    return this->find_parent(nullptr, node, start);
}

template<typename T>
std::shared_ptr<BSTreeNode<T>> BSTree<T>::find_parent(
        std::shared_ptr<BSTreeNode<T>> parent,
        std::shared_ptr<BSTreeNode<T>> node,
        std::shared_ptr<BSTreeNode<T>> start)
{
    if (start == nullptr || node == nullptr) {
        return nullptr;
    }

    if (start == node) {
        return parent;
    } else if (node->data() < start->data()) {
        return find_parent(start, node, start->_left);
    } else {
        return find_parent(start, node, start->_right);
    }
}

template<typename T>
void BSTree<T>::remove(T element)
{
    std::shared_ptr<BSTreeNode<T>> node_to_delete =
            this->find(element);

    if (node_to_delete == nullptr) {
        return;
    }

    if (node_to_delete->_left == nullptr &&
        node_to_delete->_right == nullptr) {

    }
}

template<typename T>
void BSTree<T>::inorder(std::shared_ptr<BSTreeNode<T>> start,
                        const std::function<void(std::shared_ptr<BSTreeNode<T>>)> &run_for_each_node)
{
    if (start != nullptr) {
        inorder(start->_left, run_for_each_node);
        run_for_each_node(start);
        inorder(start->_right, run_for_each_node);
    }
}

template<typename T>
void BSTree<T>::preorder(std::shared_ptr<BSTreeNode<T>> start,
                        const std::function<void(std::shared_ptr<BSTreeNode<T>>)> &run_for_each_node)
{
    if (start != nullptr) {
        run_for_each_node(start);
        inorder(start->_left, run_for_each_node);
        inorder(start->_right, run_for_each_node);
    }
}

template<typename T>
void BSTree<T>::postorder(std::shared_ptr<BSTreeNode<T>> start,
                        const std::function<void(std::shared_ptr<BSTreeNode<T>>)> &run_for_each_node)
{
    if (start != nullptr) {
        inorder(start->_left, run_for_each_node);
        inorder(start->_right, run_for_each_node);
        run_for_each_node(start);
    }
}

#endif //ALGORITHMSWORKBENCH_BSTREE_HPP
