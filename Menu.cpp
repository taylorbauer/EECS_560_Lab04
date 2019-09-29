//
//  Author: Taylor Bauer
//  Date: September 28, 2019
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(BinaryTree tree) {
    m_tree = tree;
}

void Menu::run() {
    cout << "Running...\n";
    m_tree.levelOrder(false);
    int selection = 1;
    while (selection < 11 && selection > 0) {
        cin.clear();
        cout << "\n\n------------------------------------------------------------\n";
        cout << "Please choose one of the following commands:\n";
        cout << "1- IsFull\n";
        cout << "2- AddItem\n";
        cout << "3- Delete\n";
        cout << "4- Leaf\n";
        cout << "5- PrintLeaf\n";
        cout << "6- PrintTreeHeight\n";
        cout << "7- Preorder\n";
        cout << "8- Postorder\n";
        cout << "9- Inorder\n";
        cout << "10- Levelorder\n";
        cout << "11- Exit\n";
        cout << "Your selection: ";
        cin >> selection;

        if (selection == 1) {
            if (m_tree.isFull()) {
                cout << "The tree IS full.";
            }
            else {
                cout << "The tree IS NOT full.";
            }
        }
        else if (selection == 2) {
            cin.clear();
            cout << "Please enter the value which you want to enter into the tree: ";
            int insertion;
            cin >> insertion;
            m_tree.insert(m_tree.getRoot(), insertion);
            cout << "Output: " << insertion << " inserted successfully!";
        }
        else if (selection == 3) {
            int lastValue = m_tree.remove();
            cout << "Successfully removed " << lastValue << " from the tree.";
        }
        else if (selection == 4) {
            cin.clear();
            int searchKey = 0;
            cout << "Please enter the value which you want to test as a leaf node: ";
            cin >> searchKey;
            if (m_tree.leaf(searchKey)) {
                cout << "The node with " << searchKey << " is a leaf node.";
            }
            else {
                cout << "The node with " << searchKey << " is NOT a leaf node.";
            }
        }
        else if (selection == 5) {
            m_tree.printLeaves();
        }
        else if (selection == 6) {
            cout << "The height of the tree is " << m_tree.getHeight(m_tree.getRoot()) << '.';
        }
        else if (selection == 7) {
            cout << "Printing tree in pre-order:\n";
            m_tree.preOrder(m_tree.getRoot());
        }
        else if (selection == 8) {
            cout << "Printing tree in post-order:\n";
            m_tree.postOrder(m_tree.getRoot());
        }
        else if (selection == 9) {
            cout << "Printing tree in in-order:\n";
            m_tree.inOrder(m_tree.getRoot());
        }
        else if (selection == 10) {
            cout << "Output: Printing in level-order -- ";
            m_tree.levelOrder(false);
        }
    }
    cout << "\nGoodbye!\n\n";
}