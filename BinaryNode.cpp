//
//  Author: Taylor Bauer
//  Date: September 28, 2019
//

#include "BinaryNode.h"

BinaryNode::BinaryNode(int value) {
    m_value = value;
    m_parent = nullptr;
    m_left = nullptr;
    m_right = nullptr;
}

int BinaryNode::childrenCount() {
    if (m_left == nullptr && m_right == nullptr) {
        return 0;
    }
    else if (m_left == nullptr ^ m_right == nullptr) {
        return 1;
    }
    else {
        return 2;
    }
}

BinaryNode* BinaryNode::getLeft() {
    return m_left;
}
BinaryNode* BinaryNode::getRight() {
    return m_right;
}
BinaryNode* BinaryNode::getParent() {
    return m_parent;
}
int BinaryNode::getValue() {
    return m_value;
}

bool BinaryNode::addChild(BinaryNode* child) {
    if (childrenCount() == 2) {
        return false;
    }
    else {
        if (m_left == nullptr) {
            m_left = child;
        }
        else {  // There is a left child but not a right child
            m_right = child;
        }
        child->setParent(this);

        return true;
    }
}

void BinaryNode::setParent(BinaryNode* parent) {
    m_parent = parent;
    return;
}

int BinaryNode::removeChild() {
    int value = 0;
    if (childrenCount() == 2) {
        value = m_right->getValue();
        m_right = nullptr;
        return value;
    }
    else if (childrenCount() == 1) {
        value = m_left->getValue();
        m_left = nullptr;
        return value;
    }
    else {
        return 0;
    }
}