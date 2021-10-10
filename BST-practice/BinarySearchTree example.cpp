
#include <iostream>


#include "BinarySearchTree.hxx"


int main()
{

    BinarySearchTree<int,int> tree;
    //tree.insert(7,11);
    //tree.insert(5,1);
    //tree.insert(13,10);
    //tree.insert(15,2);
    //tree.insert(9,8);
    //tree.insert(3,81);

    // test on following as well....
    tree.insert(5,1);
    tree.insert(3,34);
    tree.insert(4,2);
    tree.insert(8,6);
    tree.insert(7,1);
    tree.insert(9,4);
    tree.insert(13,6);
    tree.insert(12,2);
    tree.insert(11,1); 

    std::cout << std::endl << "Inorder Traversal: "<<std::endl;
    tree.printInorder();
    
    std::cout << std::endl << "Tree height: " << std::endl;
    std::cout << tree.height();

    std::cout << std::endl << "Node count: " << std::endl;
    std::cout << tree.countNodes();

    std::cout << std::endl << "Leaf count: " << std::endl;
    std::cout << tree.countLeaves();

    std::cout << std::endl << "Min: " << std::endl;
    std::cout << tree.findMin();

    std::cout << std::endl << "Node sum: " << std::endl;
    std::cout << tree.getNodeSum();

    std::cout << std::endl << "Leaf sum: " << std::endl;
    std::cout << tree.getLeafSum();

    std::cout << std::endl << "Descending order Traversal: " << std::endl;
    tree.printDescendingOrder();

     return 0;

}