#ifndef USER_H
#define USER_H

#include "TaskList.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

class User
{
public:
    TaskList tasks;
    User()
    {
        this->username = "";
        this->password = "";
        this->tasks = TaskList();
        this->loggedin = false;
    }
    void setPassword(std::string pw)
    {
        this->password = pw;
    }
    std::string getPassword()
    {
        return this->password;
    }
    void setName(std::string user)
    {
        this->username = user;
    }
    std::string getName()
    {

        return username;
    }
    TaskList getTaskList()
    {
        return this->tasks;
    }

    void setLoggedin(bool state)
    {
        loggedin = state;
    }

    bool getLoggedin()
    {
        return loggedin;
    }

    std::vector<int> encrypt(std::string pass, int pub, int n)
    {
        std::vector<int> encrypted;
        for (unsigned long i = 0; i < pass.size(); ++i)
        {
            char ch = pass.at(i);
            int ascii = int(ch);
            // int encrypt = binaryImplementation(ascii, 5, 1501);
            int encrypt = binaryImplementation(ascii, pub, n);
            encrypted.push_back(encrypt);
        }
        return encrypted;
    }

    std::string decrypt(std::vector<int> encrypted)
    {
        std::string decrypted = "";

        for (int i = 0; i < encrypted.size(); ++i)
        {
            int ch = encrypted.at(i);
            // int ascii = int(ch);

            // int decrypt = binaryImplementation(ch, 281, 1501);
            int decrypt = binaryImplementation(ch, 1229, 1649);
            std::cout << decrypt << " ";
            // encrypted = encrypted + std::to_string(encrypt) + " ";
            decrypted += decrypt;
        }
        std::cout << std::endl;
        return decrypted;
    }

    int binaryImplementation(int c, int d, int n)
{
    c = c % n; // c^d mod n -> (c mod n)^d
    int answer = 1;

    // d = b0001 0001 1001 -> 281
    while (d > 0)
    {
        // bitwise AND (check if value is 0 or 1)
        // if LSB is 1 then execute
        if (d & 1)
            // 1st Iteration: (1 * 55) % 1501 = 55
            // 2nd Iteration: (1 * 1265) % 1501 = 1265 (2nd if iteraton)
            answer = (answer * c) % n;

        // Bitshift left ex. d = b0001 0001 1001 -> b0000 1000 1100
        d = d >> 1;
        // C^2 mod n -> 55^2 mod 1501 -> 3025 mod 1501 -> 23
        c = (c * c) % n;
    }
    return answer;
}

private:
    std::string username;
    std::string password;
    bool loggedin;
};

#endif
