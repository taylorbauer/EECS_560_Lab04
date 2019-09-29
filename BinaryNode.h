#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode{
public:

    //  Basic constructor
    BinaryNode(int value);

    //  Returns the number of children that the node has
    int childrenCount();

    //  Returns pointers to various family  nodes
    BinaryNode* getParent();
    BinaryNode* getLeft();
    BinaryNode* getRight();

    //  Returns the value of the node
    int getValue();

    //  Adds the left or right node, depending on if it has 0 or 1 children
    //  Does nothing and returns false if it has 2 children
    bool addChild(BinaryNode* child);

    //  Deletes the last (from left to right) child and returns its value
    int removeChild();

private:
    int m_value;
    BinaryNode* m_parent;
    BinaryNode* m_left;
    BinaryNode* m_right;

    //  Sets a node's parent
    //  This is used in insertion
    void setParent(BinaryNode* parent);
};


#endif