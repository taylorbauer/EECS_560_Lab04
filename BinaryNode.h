#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode{
public:
    BinaryNode(int value);
    int childrenCount();
    BinaryNode* getParent();
    BinaryNode* getLeft();
    BinaryNode* getRight();
    int getValue();
    bool addChild(BinaryNode* child);

private:
    int m_value;
    BinaryNode* m_parent;
    BinaryNode* m_left;
    BinaryNode* m_right;
    void setParent(BinaryNode* parent);
};


#endif