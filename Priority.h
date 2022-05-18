#ifndef PRIORITY_H
#define PRIORITY_H

#include "Information.hpp"

class Priority : public Information
{
private:
    unsigned int priority;

public:
    Priority();
    Priority(unsigned int);
    unsigned int getInfo(unsigned int);
    void setInfo(unsigned int);
};

#endif
