tree: main.o segmenttree.o
	g++ -o tree main.o segmenttree.o -std=c++14

main.o: main.cpp
	g++ -c main.cpp -std=c++14

segmenttree.o: segmenttree.cpp segmenttree.hpp
	g++ -c segmenttree.cpp -std=c++14

clean:
	rm -rf *.o
	rm -rf tree
