lab3: main.o Box.o StackOfBoxes.o
	g++ -g -std=c++11 main.o Box.o StackOfBoxes.o -o lab3

Box.o: Box.h Box.cpp
	g++ -g -std=c++11 -c Box.cpp

StackOfBoxes.o: StackOfBoxes.h StackOfBoxes.cpp
	g++ -g -std=c++11 -c StackOfBoxes.cpp

main.o: main.cpp Box.o StackOfBoxes.o
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o
