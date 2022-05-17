#ifndef DUEDATE_H
#define DUEDATE_H

#include <iostream>

class DueDate {
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
	public:
		DueDate(unsigned int date);
        virtual void setInfo(unsigned int date);
        virtual unsigned int getInfo();
		
};

#endif
