#ifndef ALGORITHMSWORKBENCH_BSTREE_NODE_HPP
#define ALGORITHMSWORKBENCH_BSTREE_NODE_HPP

#include <memory>

template<typename T>
class BSTreeNode {
private:
    T _data;
    unsigned int _count;

public:
    std::shared_ptr<BSTreeNode> _left;
    std::shared_ptr<BSTreeNode> _right;

    BSTreeNode(T data);

    T data() const;
    unsigned int count() const;

    void set_data(const T& data);
    void set_count(const T& count);

    void increment_count();
    void decrement_count();
};

template<typename T>
BSTreeNode<T>::BSTreeNode(T data)
    : _data(data), _count(1),
    _left(nullptr), _right(nullptr)
{

}

template<typename T>
inline T BSTreeNode<T>::data() const
{
    return T(this->_data);
}

template<typename T>
inline unsigned int BSTreeNode<T>::count() const
{
    return this->_count;
}

template<typename T>
inline void BSTreeNode<T>::set_data(const T& data)
{
    this->_data = T(data);
}

template<typename T>
inline void BSTreeNode<T>::set_count(const T &count)
{
    this->_count = count;
}

template<typename T>
inline void BSTreeNode<T>::increment_count()
{
    ++this->_count;
}

template<typename T>
inline void BSTreeNode<T>::decrement_count()
{
    --this->_count;
}

#endif //ALGORITHMSWORKBENCH_BSTREE_NODE_HPP
