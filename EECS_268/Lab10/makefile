all: main.o MazeReader.o MazeCreationException.o
	g++ -g -std=c++11 main.o MazeReader.o MazeCreationException.o -o lab10

MazeReader.o: MazeReader.h MazeReader.cpp MazeCreationException.o
	g++ -g -std=c++11 -c MazeReader.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -c MazeCreationException.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -std=c++11 -c MazeWalker.cpp

Position.o: Position.h Position.cpp
	g++ -g -std=c++11 -c Position.cpp

main.o: main.cpp MazeReader.o
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o
	ls

wipe:
	rm lab10
	ls

	
