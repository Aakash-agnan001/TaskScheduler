#ifndef DUEDATE_H
#define DUEDATE_H

#include "Information.hpp"

class DueDate : public Information
{
private:
    std::string day;
    std::string month;
    std::string year;

public:
    DueDate()
    {
        this->day = "00";
        this->month = "00";
        this->year = "0000";
    };
    DueDate(std::string);
    virtual void setInfo(unsigned int){};
    virtual unsigned int getInfo(unsigned int) { return 0; };

    virtual void setInfo(std::string);
    virtual std::string getInfo(std::string);
};

#endif
