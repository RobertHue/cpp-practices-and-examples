#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "VoterRegistrationRecord.h"
#include <vector>
using namespace std;

// @brief	this class is used to read a text file of 
//			VoterRegistrationRecords and stores the contents inside
//			a container. With run the user gets a menu where he can
//			apply several queries on the container.
class Executive
{
private:
	vector<VoterRegistrationRecord> m_voters;
	
public:
	Executive() = delete;
	
	// @brief 	opens the file and read all records into a dynamically 
	//		 	allocated array
	Executive(char* p_fileName);
	
	// @brief	prompts for and reads from the console directives
	//			to be applied to this stored data
	void run();
};

#endif
