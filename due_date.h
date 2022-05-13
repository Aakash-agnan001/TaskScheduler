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
		DueDate(int day, int month, int year);
		void setDay(int day);
		void setMonth(int month);
		void setYear(int year);
		string getDate();
};

#endif
