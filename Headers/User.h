#ifndef USER_H
#define USER_H

#include "TaskList.h"
#include "../data.csv"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
    
    bool write_CSV() {
        std::ofstream file;
        file.open("data.csv", std::ios_base::app);
        file << this->getName() << "," << this->getPassword() << "," << tasks.getTaskList().title << "," << tasks.getTaskList().description << "," << tasks.getTaskList().date << "," << tasks.getTaskList().classification << "," << tasks.getTaskList().duration << "," << tasks.getTaskList().priority << std::endl;
        file.close();
        return true;
    }

private:
    std::string firstName;
    std::string lastName;
    std::string password;
};

#endif
