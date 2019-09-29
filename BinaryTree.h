//
//  Author: Taylor Bauer
//  Date: September 28, 2019
//
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "BinaryNode.h"

//  This class is the main purpose of this lab
//  It is a Binary Tree, inserted and traversed in level order
class BinaryTree {
public:

    //  Basic constructor
    BinaryTree();

    //  Iterates through the tree and deletes each node
    ~BinaryTree();

    //  Inserts a node in level-order
    //  This is not yet working at arbitrary depths, and only goes to a depth of 4
    void insert(BinaryNode* root, int value);

    //  Returns weather the tree is empty
    bool isEmpty();

    //  Returns if the tree is full
    bool isFull();

    //  The functions to traverse and print in level order
    //  The first one passes the root to the second, which recursively calls itself
    void levelOrder(bool leafFlag);
    void levelOrder(bool leafFlag, BinaryNode* node, int level);
    
    //  Deletes the last (level order) node from the tree
    //  Decrements node count appropriately
    int remove();

    //  Returns the root node
    //  This is used by menu to call the print functions
    BinaryNode* getRoot();

    //  Searches for the node with the value passed
    //  Returns true if found and if it is a leaf
    //  False otherwise
    bool leaf(int searchKey);

    //  Prints all leaves
    //  What this really does is calls the level-order function with a flag
    //  that tells it to just print the leaves
    void printLeaves();

    //  Returns the height of the node
    int getHeight(BinaryNode* node);

    //  These print the tree in the various orders that are not level-order
    void preOrder(BinaryNode* node);
    void postOrder(BinaryNode* node);
    void inOrder(BinaryNode* node);
private:

    //  Finds the last node inserted on the list
    //  This is the node that is deleted by remove()
    BinaryNode* findLastNode(BinaryNode* root);
    BinaryNode* m_root;
    int m_count;

    //  Returns the node that is the last parent
    BinaryNode* findLastParent(BinaryNode* node);
    bool searchForLeaf(BinaryNode* root, int searchKey);
};


#endif