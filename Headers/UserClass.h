#ifndef USERCLASS_H
#define USERCLASS_H

#include "TaskList.h"

class UserClass {
	private:
	std::string firstName;
	std::string lastName;
	std::string password;
	TaskList tasks;
};

#endif
