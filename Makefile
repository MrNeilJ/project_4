output: main.o Barbarian.o BlueMen.o Creature.o Dice.o Game.o HarryPotter.o Medusa.o Vampire.o menuMaker.o inputCheck.o
	g++ main.o Barbarian.o BlueMen.o Creature.o Dice.o Game.o HarryPotter.o Medusa.o Vampire.o menuMaker.o inputCheck.o -std=c++11 -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++11 -c BlueMen.cpp

Creature.o: Creature.cpp Creature.hpp
	g++ -std=c++11 -c Creature.cpp

Dice.o: Dice.cpp Dice.hpp
	g++ -std=c++11 -c Dice.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

menuMaker.o: menuMaker.cpp menuMaker.hpp
	g++ -std=c++11 -c menuMaker.cpp

inputCheck.o: inputCheck.cpp inputCheck.hpp
	g++ -std=c++11 -c inputCheck.cpp

clean:
	rm *.o output