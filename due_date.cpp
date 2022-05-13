#include "due_date.h"

DueDate::DueDate(unsigned int day, unsigned int month, unsigned int year)
{
        this->day = day;
        this->month = month;
        this->year = year;
}

void DueDate::setDay(unsigned int day)
{
        this->day = day;
}

void DueDate::setMonth(unsigned int month)
{
        this->month = month;
}

void DueDate::setYear(unsigned int year)
{
        this->year = year;
}

string DueDate::getDate()
{
        string day_string= to_string(this->day);
        string month_string = to_string(this->month);
        string year_string = to_string(this->year);
        
        return day_string + "/" + month_string + "/" + year_string + ".";
}
