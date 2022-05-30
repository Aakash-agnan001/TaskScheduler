#ifndef USER_H
#define USER_H

#include "TaskList.h"
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

    bool writeCSV() {
        std::ofstream file("Headers/data.txt");
        if (file.is_open())
        {
            std::string data;
            file << "POGGERS POGGERS";
            return true;
        }
        return false;
    }

    bool readCSV()
    {
        std::ifstream file("Headers/data.txt");
        if (file.is_open())
        {
            std::string data;
            while (file >> data)
            {
                // std::cout << data << std::endl;
            }
            return true;
        }
        return false;
    }

private:
    std::string firstName;
    std::string lastName;
    std::string password;
};

#endif
