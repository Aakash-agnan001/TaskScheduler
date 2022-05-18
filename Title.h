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

    unsigned int getInfo(unsigned int) {return 0;};
    void setInfo(unsigned int) {};
};

#endif
