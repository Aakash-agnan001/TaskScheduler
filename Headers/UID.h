#ifndef UID_H
#define UID_H

#include <string>
#include "Information.hpp"

class UID : public Information
{
private:
    std::string id;

public:
    UID() { this->id = ""; };
    UID(std::string);
    virtual void setInfo(std::string);
    virtual std::string getInfo(std::string);

    virtual void setInfo(unsigned int){};
    virtual unsigned int getInfo(unsigned int) { return 0; };
};

#endif
