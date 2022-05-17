#ifndef PRIORITY_H
#define PRIORITY_H

class Priority {
    private:
        unsigned int priority;
    public:
	Priority();
        Priority(unsigned int);
        unsigned int getInfo();
        void setInfo(unsigned int);
};

#endif
