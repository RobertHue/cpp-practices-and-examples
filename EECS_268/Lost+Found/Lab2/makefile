lab2: main.o Pokemon.o Dice.o
	g++ main.o Pokemon.o Dice.o -o lab2

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -c Pokemon.cpp

Dice.o: Dice.cpp Dice.h
	g++ -c Dice.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm lab2 *.o
