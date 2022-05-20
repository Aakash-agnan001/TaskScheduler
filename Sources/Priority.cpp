#include "../Headers/Priority.h"

Priority::Priority(unsigned int priority) {
    this->priority = priority;
}

unsigned int Priority::getInfo(unsigned int marker) {
    return this->priority;
}

void Priority::setInfo(unsigned int priority) {
    this->priority = priority;
}
