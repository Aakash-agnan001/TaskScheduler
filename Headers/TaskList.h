#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <list>

class TaskList : public Task {
    private:
        std::list<Task> tasks;
    public:
        void addTask(std::string title, std::string description, unsigned int classification, unsigned int priority, std::string date, unsigned int duration);
        void deleteTask(std::string title);
        void getTask(std::string title);
        void classificationSort();
        void prioritySort();
};

#endif