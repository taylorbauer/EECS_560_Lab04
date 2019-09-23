Lab04: main.o BinaryTree.o BinaryNode.o Menu.o
	g++ -std=c++11 main.o BinaryTree.o BinaryNode.o Menu.o -o Lab04
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -std=c++11 -c BinaryTree.cpp
BinaryNode.o: BinaryNode.cpp BinaryNode.h
	g++ -std=c++11 -c BinaryNode.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp

clean:
	rm -f test *.o