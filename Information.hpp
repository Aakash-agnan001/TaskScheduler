#ifndef __INFORMATION_HPP__
#define __INFORMATION_HPP__

#include <string>

class Information {
    public:
        virtual void setInfo(unsigned int) = 0;
        virtual void setInfo(std::string) = 0;
        virtual unsigned getInfo(unsigned) = 0;
        virtual std::string getInfo(std::string) = 0;
        virtual ~Information() = default;
};

#endif