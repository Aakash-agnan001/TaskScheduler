#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <iterator>
#include <list>

class TaskList : public Task
{
private:
    int size;

public:
    std::list<Task> tasks;
    TaskList();
    void addTask(std::string, std::string, unsigned int, unsigned int, std::string, unsigned int);
    void deleteTask(std::string);
    void updateTask(std::string, std::string, unsigned int, unsigned int, std::string, unsigned int);
    int getSize();
};

#endif
