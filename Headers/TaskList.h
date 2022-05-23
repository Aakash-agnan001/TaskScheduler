#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <iterator>
#include <list>

class TaskList : public Task {
    private:
        std::list<Task> tasks;
        int size;
    public:
        TaskList();
        void addTask(std::string, std::string, unsigned int, unsigned int, std::string, unsigned int);
        void deleteTask(std::string title);
        Task* getTask(std::string title);
        int getSize();
};

#endif
