#include <iostream>
#include <binary_search_tree_node.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello World!!!"
        << std::endl;

    // Test code
    std::unique_ptr<BSTNode<int>> root
        = std::make_unique<BSTNode<int>>(22);

    std::unique_ptr<BSTNode<int>> im_left
        = std::make_unique<BSTNode<int>>(10);
    std::unique_ptr<BSTNode<int>> im_right
        = std::make_unique<BSTNode<int>>(30);

    im_left->_right = std::make_unique<BSTNode<int>>(15);
    im_right->_left = std::make_unique<BSTNode<int>>(24);

    root->_left = std::move(im_left);
    root->_right = std::move(im_right);

    assert(root->data() == 22);

    assert(root->_left->data() == 10);
    assert(root->_right->data() == 30);

    assert(root->_left->_right->data() == 15);
    assert(root->_right->_left->data() == 24);

    return 0;
}