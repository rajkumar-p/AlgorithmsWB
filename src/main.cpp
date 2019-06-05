#include <iostream>
#include "bstree.hpp"

int main(int argc, char *argv[])
{
    std::shared_ptr<BSTree<unsigned int>> bstree(
            std::make_shared<BSTree<unsigned int>>(15));

    bstree->add_element(5);
    bstree->add_element(16);
    bstree->add_element(3);
    bstree->add_element(12);
    bstree->add_element(20);

    std::function<void(std::shared_ptr<BSTreeNode<unsigned int>>)>
            f = [](std::shared_ptr<BSTreeNode<unsigned int>> node) {
        std::cout << node->data() << "\t";
    };

    bstree->inorder_traversal(bstree->root(), f);
    std::cout <<std::endl;

    return 0;
}