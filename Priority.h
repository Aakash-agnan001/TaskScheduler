#ifndef PRIORITY_H
#define PRIORITY_H

#include "Information.hpp"

class Priority : public Information {
    private:
        unsigned int priority;
    public:
	Priority();
        Priority(unsigned int);
        virtual void getPriority();
        virtual void setPriority(unsigned int);
};

#endif
