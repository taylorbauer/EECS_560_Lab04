//
//  Author: Taylor Bauer
//  Date: September 28, 2019
//

#ifndef MENU_H
#define MENU_H
#include "BinaryTree.h"

//  Menu is the class that handles all user interaction and management of the tree
class Menu {
public:

    //  Initializes a menu with a tree passed by value
    Menu(BinaryTree tree);

    //  This function is a loop that handles all user interaction
    void run();
private:

    //  The binary tree
    //  It is not a pointer! This relieved a lot of memory management headaches
    BinaryTree m_tree;
};

#endif