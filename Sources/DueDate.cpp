#include "../Headers/DueDate.h"

DueDate::DueDate(std::string date_str)
{
    this->month = date_str.substr(0, 2);
    this->day = date_str.substr(2, 2);
    this->year = date_str.substr(4, 4);
}

void DueDate::setInfo(std::string date_str)
{
    this->month = date_str.substr(0, 2);
    this->day = date_str.substr(2, 2);
    this->year = date_str.substr(4, 4);
}

std::string DueDate::getInfo(std::string marker)
{
    return this->month + this->day + this->year;
}