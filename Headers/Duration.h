#ifndef DURATION_H
#define DURATION_H

#include "Information.hpp"

class Duration : public Information
{
private:
    unsigned int minutes;

public:
    Duration(){ this->minutes = 1;};
    Duration(unsigned minutes);
    virtual void setInfo(unsigned int);
    virtual unsigned int getInfo(unsigned int);

    virtual void setInfo(std::string){};
    virtual std::string getInfo(std::string) { return ""; };
};

#endif
