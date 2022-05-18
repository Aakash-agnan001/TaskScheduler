#ifndef UID_H
#define UID_H

#include <string>
#include "Information.hpp"

class UID : public Information
{
private:
    std::string id;

public:
    UID(std::string);
    void setInfo(std::string);
    std::string getInfo(std::string);
};

#endif
