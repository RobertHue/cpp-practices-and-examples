#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "MathToolsInterface.h"
#include "MathTools.h"

class Executive
{
private:
	MathToolsInterface& mathTools;
public:
	Executive();
	
	// @brief	prompts for and reads from the console directives
	void run();
};

#endif
