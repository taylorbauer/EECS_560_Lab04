//
//  Author: Taylor Bauer
//  Date: September 28, 2019
//

#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {
    m_root = nullptr;
    m_count = 0;
}

BinaryTree::~BinaryTree() {
    //TODO: Build destructor
}

bool BinaryTree::isFull() {
    //cout << "isFull is getting called\n";
    int iterator = 1;
    while (iterator <= m_count + 1) {
        if (iterator == m_count + 1) {
            //cout << "I think I'm full\n";
            return true;
        } 
        iterator = iterator * 2;
    }
    //cout << "I don't think I'm full because count is " << m_count << " and iterator is " << iterator << endl;
    return false;
}

void BinaryTree::insert(BinaryNode* root, int value) {
    BinaryNode* tempNode = new BinaryNode(value);
    //cout << "made a new node with value " << tempNode->getValue() << endl;

    //  Insert on an empty tree
    if (isEmpty()) {
        m_root = tempNode;
        //cout << "I think I'm empty\n";
    }
    else {
        //cout << "I don't think I'm empty\n";
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

int BinaryTree::remove() {
    BinaryNode* lastNode = findLastNode(m_root);
    m_count --;
    return lastNode->getParent()->removeChild();
}

BinaryNode* BinaryTree::findLastNode(BinaryNode* root) {
    if (root->childrenCount() == 2) {
        return findLastNode(root->getRight());
    }
    else if (root->childrenCount() == 1) {
        return findLastNode(root->getLeft());
    }
    else if (root ->childrenCount() == 0) {
        return root;
    }
    else {
        cout << "\n\nBIG ERROR IN findLastNode\n\n";
        return root;
    }
}

bool BinaryTree::leaf(int searchKey) {
    bool found = searchForLeaf(m_root, searchKey);
    return (found);
}

bool BinaryTree::searchForLeaf(BinaryNode* root, int searchKey) {
    if (root->getValue() == searchKey) {
        return (root->childrenCount() == 0);
    }
    if (root->childrenCount() != 0 && searchForLeaf(root->getLeft(), searchKey)) {
        return true;
    }
    if (root->childrenCount() == 2 && searchForLeaf(root->getRight(), searchKey)) {
        return true;
    }
    return false;
}

//  So far, this should only be called on a non-empty and non-complete tree
BinaryNode* BinaryTree::findLastParent(BinaryNode* node) {
    //cout << "Find last parent is being called on " << node->getValue() << endl;
    BinaryNode* furthestRight = node;
    //cout << "The furthest right node has " << furthestRight->childrenCount() << " children\n";
    while (furthestRight->childrenCount() == 2) {
        furthestRight = furthestRight->getRight();
    }
    //cout << "The furthest right node has " << furthestRight->childrenCount() << " children\n";

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

void BinaryTree::levelOrder(bool leafFlag) {
    int height = getHeight(m_root);
    for (int i = 0; i < height; i++) {
        levelOrder(leafFlag, m_root, i);
    }
}

void BinaryTree::levelOrder(bool leafFlag, BinaryNode* node, int level) {
    if (node == nullptr) {
        return;
    }
    else if (level == 0) {
        if (leafFlag == true) {
            if (node->childrenCount() == 0) {
                cout << node->getValue() << ' ';
            }
        }
        else{
            cout << node->getValue() << ' ';
        }
    }
    else {
        levelOrder(leafFlag, node->getLeft(), level - 1);
        levelOrder(leafFlag, node->getRight(), level - 1);
    }
}


void BinaryTree::printLeaves(){
    levelOrder(true);
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

void BinaryTree::preOrder(BinaryNode* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->getValue() << ' ';
    preOrder(node->getLeft());
    preOrder(node->getRight());
    return;
}

void BinaryTree::postOrder(BinaryNode* node) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->getLeft());
    postOrder(node->getRight());
    cout << node->getValue() << ' ';
    return;
}

void BinaryTree::inOrder(BinaryNode* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->getLeft());
    cout << node->getValue() << ' ';
    inOrder(node->getRight());
    return;
}


BinaryNode* BinaryTree::getRoot(){
    return m_root;
}
