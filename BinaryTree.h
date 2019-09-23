#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "BinaryNode.h"

class BinaryTree {
public:
    BinaryTree();
    void insert(int value);
    bool isEmpty();
    bool isFull();
    void levelOrder(BinaryNode* node, int level);
    void levelOrder();
private:
    BinaryNode* m_root;
    int m_count;
    BinaryNode* findLastParent(BinaryNode* node);
    int getHeight(BinaryNode* node);
};


#endif