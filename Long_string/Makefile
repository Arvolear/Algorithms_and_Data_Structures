longstring: main.o longstring.o
	g++ -o longstring main.o longstring.o --std=c++14 -O3

main.o: main.cpp
	g++ -c main.cpp --std=c++14

longstring.o: longstring.cpp
	g++ -c longstring.cpp --std=c++14

clean:
	rm -f longstring
	rm -f *.o
