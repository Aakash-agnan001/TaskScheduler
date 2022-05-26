#ifndef USER_H
#define USER_H

#include "TaskList.h"

class User
{
public:
    TaskList tasks;
    User()
    {
        this->firstName = "";
        this->lastName = "";
        this->password = "";
        this->tasks = TaskList();
    }
    void setPassword(std::string pw)
    {
        this->password = pw;
    }
    std::string getPassword()
    {
        return this->password;
    }
    void setName(std::string fn, std::string ln)
    {
        this->firstName = fn;
        this->lastName = ln;
    }
    std::string getName()
    {
        std::string tempString = this->firstName;
        tempString = tempString + " ";
        tempString = tempString + this->lastName;
        return tempString;
    }
    TaskList getTaskList()
    {
        return this->tasks;
    }

private:
    std::string firstName;
    std::string lastName;
    std::string password;
};

#endif
