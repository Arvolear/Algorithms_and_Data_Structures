flags = -std=c++14

tree: main.o implicitcartesiantree.o
	g++ -o tree main.o implicitcartesiantree.o $(flags)

main.o: main.cpp
	g++ -c main.cpp $(flags)

implicitcartesiantree.o: implicitcartesiantree.cpp implicitcartesiantree.hpp
	g++ -c implicitcartesiantree.cpp $(flags)

clean:
	rm -rf *.o
	rm -rf tree
