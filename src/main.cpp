#include "bstree_node.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::shared_ptr<BSTreeNode<unsigned int>>
            node(new BSTreeNode<unsigned int>(15));

    std::cout <<"Node data : "<<node->data()<<std::endl;
    std::cout <<"Node data(count) : "<<node->count()<<std::endl;

    std::shared_ptr<BSTreeNode<unsigned int>>
            left(new BSTreeNode<unsigned int>(10));
    std::shared_ptr<BSTreeNode<unsigned int>>
            right(new BSTreeNode<unsigned int>(20));

    node->left = left;
    node->right = right;

    std::cout <<"Node left data : "<<node->left->data()<<std::endl;
    std::cout <<"Node left data(count) : "<<node->left->count()<<std::endl;
    std::cout <<"Node right data : "<<node->right->data()<<std::endl;
    std::cout <<"Node right data(count) : "<<node->right->count()<<std::endl;

    return 0;
}