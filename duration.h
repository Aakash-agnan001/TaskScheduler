#ifndef DURATION_H
#define DURATION_H

#include <iostream>
#include <string>

using namespace std;

class Duration 
{
	private:
		unsigned int hours;
		unsigned int minutes;
	public:
		Duration(unsigned int hours, unsigned minutes);
		string getHours();
		string getMinutes();
};

#endif
