#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {
    m_root = nullptr;
    m_count = 0;
}

bool BinaryTree::isFull() {
    cout << "isFull is getting called\n";
    int iterator = 1;
    while (iterator <= m_count + 1) {
        if (iterator == m_count + 1) {
            cout << "I think I'm full\n";
            return true;
        } 
        iterator = iterator * 2;
    }
    cout << "I don't think I'm full because count is " << m_count << " and iterator is " << iterator << endl;
    return false;
}

void BinaryTree::insert(int value) {
    BinaryNode* tempNode = new BinaryNode(value);
    cout << "made a new node with value " << tempNode->getValue() << endl;

    //  Insert on an empty tree
    if (isEmpty()) {
        m_root = tempNode;
        cout << "I think I'm empty\n";
    }
    else {
        cout << "I don't think I'm empty\n";
        //Insert on a full tree
        if (isFull()) {
            BinaryNode* nodePtr = m_root;
            while (nodePtr->childrenCount() != 0) {
               nodePtr = nodePtr->getLeft();
            }
            if (!nodePtr->addChild(tempNode)) {
                cout << "\n\nBIG ERROR ADDING CHILD\n\n";
            }
        }
        
        //Insert on an incomplete tree
        else {
            BinaryNode* lastIncomplete = findLastParent(m_root);            
            lastIncomplete->addChild(tempNode);
        }
    }

    cout << value << " inserted successfully\n";
    m_count ++;
}

//  So far, this should only be called on a non-empty and non-complete tree
BinaryNode* BinaryTree::findLastParent(BinaryNode* node) {
    cout << "Find last parent is being called on " << node->getValue() << endl;
    BinaryNode* furthestRight = node;
    cout << "The furthest right node has " << furthestRight->childrenCount() << " children\n";
    while (furthestRight->childrenCount() == 2) {
        furthestRight = furthestRight->getRight();
    }
    cout << "The furthest right node has " << furthestRight->childrenCount() << " children\n";

    if (furthestRight->childrenCount() == 1) {
        return furthestRight;
    }

    //  At this point, furthestright is the bottom leaf on the right edge
    BinaryNode* leftSibling = furthestRight->getParent()->getLeft();
    if (leftSibling->childrenCount() == 2) {
        return furthestRight;
    }
    else if(leftSibling->childrenCount() == 1) {
        return leftSibling;
    }

    //  Now we know that the bottom right leaf's parent is full

    return (findLastParent(furthestRight->getParent()->getParent()->getLeft()));

}

void BinaryTree::levelOrder() {
    int height = getHeight(m_root);
    for (int i = 0; i < height; i++) {
        levelOrder(m_root, i);
    }
}

void BinaryTree::levelOrder(BinaryNode* node, int level) {
    if (node == nullptr) {
        return;
    }
    else if (level == 0) {
        cout << node->getValue() << ' ';
    }
    else {
        levelOrder(node->getLeft(), level - 1);
        levelOrder(node->getRight(), level - 1);
    }
}

bool BinaryTree::isEmpty() {
    if (m_root == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

int BinaryTree::getHeight(BinaryNode* node) {
    int height = 0;
    while (node != nullptr) {
        height ++;
        node = node->getLeft();
    }
    return height;
}