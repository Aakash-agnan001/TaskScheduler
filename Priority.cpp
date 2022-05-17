#include "Priority.h"

Priority::Priority() {
	this->priority = 0;
}

Priority::Priority(unsigned int priority) {
    this->priority = priority;
}

unsigned int Priority::getInfo() {
    return this->priority;
}

void Priority::setInfo(unsigned int priority) {
    this->priority = priority;
}
