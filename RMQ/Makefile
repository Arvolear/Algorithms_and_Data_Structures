flags = -std=c++14 -Wall -pedantic

rmq: main.o rmq.o fulltables.o sparsetable.o cartesiantree.o
	g++ -o rmq main.o rmq.o fulltables.o sparsetable.o cartesiantree.o $(flags)

main.o: main.cpp
	g++ -c main.cpp $(flags)

rmq.o: rmq.cpp rmq.hpp
	g++ -c rmq.cpp $(flags)

fulltables.o: fulltables.cpp fulltables.hpp
	g++ -c fulltables.cpp $(flags)

sparsetable.o: sparsetable.cpp sparsetable.hpp
	g++ -c sparsetable.cpp $(flags)

cartesiantree.o: cartesiantree.cpp cartesiantree.hpp
	g++ -c cartesiantree.cpp $(flags)

clean:
	rm -rf *.o
	rm -rf rmq
