#ifndef DUEDATE_H
#define DUEDATE_H

#include "Information.hpp"

class DueDate : public Information{
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
	public:
		DueDate(unsigned int date);
        virtual void setInfo(unsigned int date);
        virtual unsigned int getInfo(unsigned int);
		
};

#endif
