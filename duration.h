#ifndef DURATION_H
#define DURATION_H

#include "Information.hpp"

class Duration : public Information
{
private:
    unsigned int minutes;

public:
    Duration(unsigned minutes);
    virtual void setInfo(unsigned int);
    virtual unsigned int getInfo(unsigned);
};

#endif
