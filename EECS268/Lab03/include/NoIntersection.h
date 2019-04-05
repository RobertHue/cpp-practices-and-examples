#ifndef NO_INTERSECTION_H
#define NO_INTERSECTION_H

#include <exception>

class NoIntersection : public std::exception
{
private:
	
public:
	virtual const char* what() const throw()
	{
		return "There is no intersection between the Line and the Unit Circle!";
	}
};



#endif
