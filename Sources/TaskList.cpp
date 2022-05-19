#include "../Headers/TaskList.h"

void TaskList::addTask(std::string title, std::string description, unsigned int classification, unsigned int priority, std::string date, unsigned int duration) {
    Task task;
    task.title.setInfo(title);
    task.description.setInfo(description);
    task.classification.setInfo(classification);
    task.priority.setInfo(priority);
    task.duration.setInfo(duration);
    task.date.setInfo(date);

    tasks.push_back(task);
}

void TaskList::deleteTask(std::string title) {
    for (auto ptr = this->tasks.begin(); ptr != this->tasks.end(); ++ptr) {
        if((*ptr).title.getInfo("") == title){
            tasks.erase(ptr);
        }
    }
}

Task TaskList::getTask(std::string title) {
    for (auto ptr = this->tasks.begin(); ptr != this->tasks.end(); ++ptr) {
        if((*ptr).title.getInfo("") == title){
            return *ptr;
        }
    }
}