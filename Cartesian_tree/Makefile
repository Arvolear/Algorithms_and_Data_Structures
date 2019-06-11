flags = -std=c++14

tree: main.o cartesiantree.o
	g++ -o tree main.o cartesiantree.o $(flags)

main.o: main.cpp
	g++ -c main.cpp $(flags)

cartesiantree.o: cartesiantree.cpp cartesiantree.hpp
	g++ -c cartesiantree.cpp $(flags)

clean:
	rm -rf *.o
	rm -rf tree
