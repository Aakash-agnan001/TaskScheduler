#include "Priority.h"

Priority::Priority(unsigned int priority) {
    this->priority = priority;
}

unsigned int Priority::getPriority() {
    return this->priority;
}

void Priority::setPriority(unsigned int priority) {
    this->priority = priority;
}