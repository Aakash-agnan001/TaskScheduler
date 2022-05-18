#ifndef UID_H
#define UID_H

#include <string>

using namespace std;

class UID {
	private:
	string id;
	
	public:
	UID(string);
	void setInfo(string ident);
	string getInfo();
};

#endif 
