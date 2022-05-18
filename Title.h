#ifndef TITLE_H
#define TITLE_H

#include <string>
#include "Information.hpp"

class Title : public Information
{
private:
    std::string title;

public:
    Title(std::string);
    std::string getInfo(std::string);
    void setInfo(std::string);
};

#endif
