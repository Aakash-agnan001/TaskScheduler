#ifndef USERCLASS_H
#define USERCLASS_H

#include "TaskList.h"

class UserClass {
	public:
	TaskList tasks;
	void setPassword(std::string pw) {
		this->password = pw;	
	}
	std::string getPassword() {
		return this->password;
	}
	void setName(std::string fn, std::string ln) {
		this->firstName = fn;
		this->lastName = ln;
	}
	std::string getName() {
		std::string tempString = this->firstName;
		tempString = tempString + " ";
		tempString = tempString + this->lastName;
		return tempString;
	}
	private:
	std::string firstName;
	std::string lastName;
	std::string password;
	
};

#endif
