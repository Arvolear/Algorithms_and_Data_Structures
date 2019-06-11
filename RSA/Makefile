rsa: main.o Encryption.o PrimeRand.o LongString.o
	g++ -o rsa main.o Encryption.o PrimeRand.o LongString.o -std=c++14 -O3

main.o: main.cpp
	g++ -c main.cpp -std=c++14

Encryption.o: Encryption.cpp
	g++ -c Encryption.cpp -std=c++14

PrimeRand.o: PrimeRand.cpp
	g++ -c PrimeRand.cpp -std=c++14

LongString.o: LongString.cpp
	g++ -c LongString.cpp -std=c++14

clean:
	rm -rf rsa
	rm -rf *.o
