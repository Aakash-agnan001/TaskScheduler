#ifndef DESCRIPTION_H
#define DESCRIPTION_H
#include <iostream>
#include <string>

using namespace std;

class Description {
	private:
		string description;
	public:
		Description();
		void setDescription(string s);
		string getDescription();
};

#endif
