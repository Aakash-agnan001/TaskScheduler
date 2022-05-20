#ifndef PRIORITY_H
#define PRIORITY_H

#include "Information.hpp"
#include <string>

class Priority : public Information
{
private:
    unsigned int priority;

public:
    Priority() {this->priority = 1;};
    Priority(unsigned int);
    virtual unsigned int getInfo(unsigned int);
    virtual void setInfo(unsigned int);

    virtual std::string getInfo(std::string) { return ""; };
    virtual void setInfo(std::string){};
};

#endif
