EXEC = Voter_Registration

.PHONY = all
all: $(EXEC) cleanobj

CC		= g++
CFLAGS  = -std=c++11 -g -Wall
LDFLAGS = -std=c++11 -g -Wall

######################################################################
# link all objectfiles to an executable
$(EXEC): main.o Executive.o VoterRegistrationRecord.o
	g++ $^ -o $@ $(LDFLAGS)

# compile main.cpp
main.o: main.cpp Executive.h
	$(CC) $(CFLAGS) -c main.cpp
	
# compile Executive.cpp
Executive.o: Executive.h Executive.cpp
	$(CC) $(CFLAGS) -c Executive.cpp

# compile VoterRegistrationRecord.cpp
VoterRegistrationRecord.o: VoterRegistrationRecord.h VoterRegistrationRecord.cpp
	$(CC) $(CFLAGS) -c VoterRegistrationRecord.cpp

##########################################################
# explicitly request a phony target (= a target which is not a file)
.PHONY = cleanall cleanobj 

# removes the object files and the executable files
cleanall: cleanobj
	rm $(EXEC)
cleanobj: 
	rm *.o
