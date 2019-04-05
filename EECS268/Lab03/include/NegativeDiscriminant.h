#ifndef NEGATIVE_DISCRIMINANT_H
#define NEGATIVE_DISCRIMINANT_H

#include <exception>

class NegativeDiscriminant : public std::exception
{
private:
	
public:
	virtual const char* what() const throw()
	{
		return "Discriminant cannot be negative!\nPlease choose lower values for parameter a and c!";
	}
};



#endif
