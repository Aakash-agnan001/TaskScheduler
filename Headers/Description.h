#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <string>
#include "Information.hpp"

class Description : public Information
{
private:
    std::string description;

public:
    Description() { this->description = ""; };
    Description(std::string);
    
    virtual void setInfo(unsigned int){};
    virtual unsigned int getInfo(unsigned int) { return 0; };

    virtual void setInfo(std::string);
    virtual std::string getInfo(std::string);
};

#endif
