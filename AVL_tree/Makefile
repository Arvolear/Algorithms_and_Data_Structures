tree: AVLCommands.o AVL.o
	g++ -o tree AVLCommands.o AVL.o -std=c++14

AVLCommands.o: AVLCommands.cpp
	g++ -c AVLCommands.cpp -std=c++14

AVL.o: AVL.cpp AVL.hpp
	g++ -c AVL.cpp -std=c++14

clean:
	rm -rf *.o
	rm -rf tree
