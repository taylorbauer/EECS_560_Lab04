#ifndef MENU_H
#define MENU_H
#include "BinaryTree.h"

class Menu {
public:
    Menu(BinaryTree tree);
    void run();
private:
    BinaryTree m_tree;
};

#endif