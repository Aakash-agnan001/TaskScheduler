#ifndef DUE_DATE_H
#define DUE_DATE_H

#include <iostream>
#include <string> 

using namespace std;

class DueDate {
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
	public:
		DueDate(unsigned int day, unsigned int month, unsigned int year);
		void setDay(unsigned int day);
		void setMonth(unsigned int month);
		void setYear(unsigned int year);
		string getDate();
};

#endif
