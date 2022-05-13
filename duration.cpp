include "duration.h"

Duration::Duration(unsigned int hours, unsigned int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}

string Duration::getHours()
{
	string hours_string = to_string(hours);
	return hours_string;
}

string Duration::getMinutes() 
{	string minutes_string = to_string(minutes);
	return minutes_string;

}
