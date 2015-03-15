all: main.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o
	g++ -g -std=c++11 FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o main.o -o lab8

FarmAnimal.o: FarmAnimal.h  FarmAnimal.cpp
	g++ -g -std=c++11 -c FarmAnimal.cpp

Cow.o: Cow.h Cow.cpp FarmAnimal.o
	g++ -g -std=c++11 -c Cow.cpp

Chicken.o: Chicken.h Chicken.cpp FarmAnimal.o
	g++ -g -std=c++11 -c Chicken.cpp

CyberChicken.o: CyberChicken.h CyberChicken.cpp FarmAnimal.o Chicken.o
	g++ -g -std=c++11 -c CyberChicken.cpp

AnimalPen.o: AnimalPen.h AnimalPen.cpp FarmAnimal.o
	g++ -g -std=c++11 -c AnimalPen.cpp

main.o: main.cpp FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o

wipe:
	rm lab8
