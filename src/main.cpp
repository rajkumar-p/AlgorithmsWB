#include <iostream>
#include <vector>
#include "bstree.hpp"

int main(int argc, char *argv[])
{
    std::vector<unsigned int> elements =
            { 5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22 };

    std::shared_ptr<BSTree<unsigned int>> bstree(
            std::make_shared<BSTree<unsigned int>>(15));
    bstree->insert(elements);

    std::shared_ptr<BSTreeNode<unsigned int>> node =
            bstree->find(20);

    std::cout << "Found node 20. Left: " << node->_left->data()
        << " & Right: " << node->_right->data() << std::endl;

    std::shared_ptr<BSTreeNode<unsigned int>> null_node =
            bstree->find(155);
    std::cout << null_node << std::endl;

    bstree->inorder(bstree->root(),
                    [](std::shared_ptr<BSTreeNode<unsigned int>> node) {
                        std::cout << node->data() << "\t";
                    });
    std::cout <<std::endl;

    return 0;
}