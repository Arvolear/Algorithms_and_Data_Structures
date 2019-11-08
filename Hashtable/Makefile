flags = -std=c++11 -Wall

hashtable: main.o hashtable.o
	g++ -o hashtable main.o hashtable.o $(flags)

main.o: main.cpp
	g++ -c main.cpp $(flags)

hashtable.o: hashtable.cpp hashtable.hpp
	g++ -c hashtable.cpp $(flags)

clean:
	rm -rf hashtable
	rm -rf *.o
