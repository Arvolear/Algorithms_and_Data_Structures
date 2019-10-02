flags = -std=c++11 -Wall

red-black: main.o red-black.o
	g++ -o red-black main.o red-black.o $(flags)

main.o: main.cpp
	g++ -c main.cpp $(flags)

red-black.o: red-black.cpp red-black.hpp
	g++ -c red-black.cpp $(flags)

clean:
	rm -rf red-black
	rm -rf *.o
