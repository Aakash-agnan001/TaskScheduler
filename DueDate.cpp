#include "DueDate.h"

DueDate::DueDate(unsigned int date)
{
    std::string date_str = std::to_string(date);

    std::string month_str = date_str.substr(0, 2);
    this->month = stoi(month_str);

    std::string day_str = date_str.substr(2, 2);
    this->day = stoi(day_str);

    std::string year_str = date_str.substr(4, 4);
    this->year = stoi(year_str);
}

void DueDate::setInfo(unsigned int date)
{
    std::string date_str = std::to_string(date);

    std::string month_str = date_str.substr(0, 2);
    this->month = stoi(month_str);

    std::string day_str = date_str.substr(2, 2);
    this->day = stoi(day_str);

    std::string year_str = date_str.substr(4, 4);
    this->year = stoi(year_str);
}

unsigned int DueDate::getInfo(unsigned int marker)
{
    int month = this->month;
    std::string month_str = std::to_string(month);

    int day = this->day;
    std::string day_str = std::to_string(day);

    int year = this->year;
    std::string year_str = std::to_string(year);

    std::string date_str = month_str + date_str + year_str;
    int date = stoi(date_str);
    
    return date;
}