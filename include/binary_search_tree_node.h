#ifndef ALGORITHMSWORKBENCH_BINARY_SEARCH_TREE_NODE_H
#define ALGORITHMSWORKBENCH_BINARY_SEARCH_TREE_NODE_H

#include <memory>
#include <iostream>

template<typename T>
class BSTNode {
private:
    T _data;

public:
    std::unique_ptr<BSTNode> _left;
    std::unique_ptr<BSTNode> _right;

public:
    BSTNode(T data);
    ~BSTNode();

    T data() const;
};

template<typename T>
BSTNode<T>::BSTNode(T data)
    : _data(data), _left(nullptr), _right(nullptr)
{

}

template<typename T>
BSTNode<T>::~BSTNode()
{
    std::cout << "Removing node with data: " << this->data() << std::endl;
    _left = nullptr;
    _right = nullptr;
}

template<typename T>
T BSTNode<T>::data() const
{
    return _data;
}

#endif //ALGORITHMSWORKBENCH_BINARY_SEARCH_TREE_NODE_H
