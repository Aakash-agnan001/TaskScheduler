#ifndef DUEDATE_H
#define DUEDATE_H

#include "Information.hpp"

class DueDate : public Information{
	private:
		std::string day;
		std::string month;
		std::string year;
	public:
		DueDate(std::string);
        virtual void setInfo(unsigned int) {};
        virtual unsigned int getInfo(unsigned int) {return 0;};

        virtual void setInfo(std::string);
        virtual std::string getInfo(std::string);
		
};

#endif
