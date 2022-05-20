#include "../Headers/Duration.h"

Duration::Duration(unsigned int minutes)
{
	this->minutes = minutes;
}

void Duration::setInfo(unsigned int minutes) {
    this->minutes = minutes;
}

unsigned int Duration::getInfo(unsigned int marker) 
{	
	return this->minutes;
}
