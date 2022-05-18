#ifndef PRIORITY_H
#define PRIORITY_H

class Priority {
    private:
        unsigned int priority;
    public:
	Priority();
        Priority(unsigned int);
        void getPriority();
        void setPriority(unsigned int);
};

#endif
