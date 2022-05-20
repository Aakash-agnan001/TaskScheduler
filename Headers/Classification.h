#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include "Information.hpp"
#include <string>

class Classification : public Information
{
private:
    unsigned classification;

public:
    Classification() { this->classification = 1; };
    Classification(unsigned);
    virtual void setInfo(unsigned);
    virtual unsigned getInfo(unsigned marker);

    virtual void setInfo(std::string){};
    virtual std::string getInfo(std::string) { return ""; };
};

#endif
