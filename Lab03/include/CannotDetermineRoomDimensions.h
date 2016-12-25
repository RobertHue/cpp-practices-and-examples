#ifndef CANNOT_DETERMINE_ROOM_DIMENSION_H
#define CANNOT_DETERMINE_ROOM_DIMENSION_H

#include <exception>

class CannotDetermineRoomDimensions : public std::exception
{
private:
	
public:
	virtual const char* what() const throw()
	{
		return "Cannot determine Room Dimensions!\nEither there is no ballrom of requirement width=length+E or\nThe minRequirement for the lenght is not met!";
	}
};


#endif
