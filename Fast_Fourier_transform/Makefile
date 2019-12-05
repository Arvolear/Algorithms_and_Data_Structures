flags = -std=c++11 -Wall

fourier: main.o
	g++ -o fourier main.o $(flags)

main.o: main.cpp
	g++ -c main.cpp $(flags)

clean:
	rm -rf *.o
	rm -rf fourier
