#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "BinaryNode.h"

class BinaryTree {
public:
    BinaryTree();
    void insert(BinaryNode* root, int value);
    bool isEmpty();
    bool isFull();
    void levelOrder(bool leafFlag, BinaryNode* node, int level);
    void levelOrder(bool leafFlag);
    int remove();
    BinaryNode* getRoot();
    bool leaf(int searchKey);
    void printLeaves();
    int getHeight(BinaryNode* node);
    void preOrder(BinaryNode* node);
    void postOrder(BinaryNode* node);
    void inOrder(BinaryNode* node);
private:
    BinaryNode* findLastNode(BinaryNode* root);
    BinaryNode* m_root;
    int m_count;
    BinaryNode* findLastParent(BinaryNode* node);
    bool searchForLeaf(BinaryNode* root, int searchKey);
};


#endif