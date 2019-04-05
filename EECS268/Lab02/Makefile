EXEC = Infection_Outbreak
TEST = TestLinkedList
PATH_TO_BOOST = /usr/local

.PHONY = all
all: $(EXEC)

CC		= g++
# c++11 standard | additionally debug information | all warnings
CFLAGS  = -std=c++11 -g -Wall -I$(PATH_TO_BOOST)/include
LDFLAGS = -std=c++11 -g -Wall -L$(PATH_TO_BOOST)/lib -lboost_unit_test_framework

###################################################################### 
# link all objectfiles to an executable
$(TEST): TestLinkedList.o MedicalExecutive.o City.o
	g++ $^ -o $@ $(LDFLAGS)
	
# compile TestLinkedList.o if MedicalExecutive.cpp MedicalExecutive.h City.h LinkedList.h LinkedList.hpp Node.h or Node.hpp changed
TestLinkedList.o: TestLinkedList.cpp MedicalExecutive.h City.h LinkedList.h LinkedList.hpp Node.h
	$(CC) $(CFLAGS) -c $<
###################################################################### 

# link all objectfiles to an executable
$(EXEC): main.o City.o MedicalExecutive.o
	g++ $^ -o $@ $(LDFLAGS)
 
# compile main.o if main.cpp MedicalExecutive.h changed
main.o: main.cpp MedicalExecutive.h
	$(CC) $(CFLAGS) -c $<
	
# compile City.o if City.cpp MedicalExecutive.h changed
City.o: City.cpp City.h
	$(CC) $(CFLAGS) -c $<
	
# compile MedicalExecutive.o if MedicalExecutive.cpp MedicalExecutive.h City.h LinkedList.h LinkedList.hpp Node.h or Node.hpp changed
MedicalExecutive.o: MedicalExecutive.cpp MedicalExecutive.h City.h LinkedList.h LinkedList.hpp Node.h
	$(CC) $(CFLAGS) -c $<

##########################################################
# explicitly request a phony target (= a target which is not a file)
.PHONY = cleanall cleanexe cleanobj 

# removes the object files and the executable files
cleanall: cleanexe cleanobj
cleanexe:
	rm $(EXEC) $(TEST)
cleanobj: 
	rm *.o
