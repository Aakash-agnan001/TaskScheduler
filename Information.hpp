#ifndef __INFORMATION_HPP__
#define __INFORMATION_HPP__

class Information {
    public:
        virtual void setInfo(unsigned int) = 0;
        virtual void setInfo(std::string) = 0;
        virtual unsigned getInfo() = 0;
        virtual std::string getInfo() = 0;
};

#endif