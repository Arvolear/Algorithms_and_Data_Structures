main: main.o AVL.o
	g++ -o main main.o AVL.o -std=c++14

main.o: main.cpp
	g++ -c main.cpp -std=c++14

AVL.o: AVL.cpp AVL.hpp
	g++ -c AVL.cpp -std=c++14

clean:
	rm -rf *.o
	rm -rf main
