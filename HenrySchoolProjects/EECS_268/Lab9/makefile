all: main.o
	g++ -g -std=c++11 main.o -o lab9

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp

main.o: main.cpp QueueInterface.h Queue.h Queue.hpp PreconditionViolationException.o
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o

wipe:
	rm lab9
