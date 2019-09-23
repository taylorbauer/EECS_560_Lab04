#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "BinaryNode.h"
#include "Menu.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "\nPlease make sure you are including a filename in the command line!\n";
        cout << "Ex: ./Lab04 data.txt\n\n";
        return 0;
    }

    fstream myFile;
    myFile.open(argv[1]);

    if (!myFile) {
        cout << "\nError opening file! Please make sure it is a valid file and try again.\n\n";
    }
    else {
        cout << "\nSuccessfully opened file.\n\n";
    }

    int valueCount = 0;
    int currentValue = 0;
    while (!myFile.eof()){
        myFile >> currentValue;
        valueCount ++;
    }

    myFile.close();
    myFile.open(argv[1]);

    int* tempArr = new int[valueCount];
    for (int i; i < valueCount; i++) {
        myFile >> tempArr[i];
    }
    myFile.close();

    BinaryTree myTree;
    for(int i = 0; i < valueCount; i++) {
        cout << "Inserting: " << tempArr[i] << endl;
        myTree.insert(tempArr[i]);
    }

    Menu mainMenu(myTree);
    mainMenu.run();

    delete[] tempArr;
    return 0;
}