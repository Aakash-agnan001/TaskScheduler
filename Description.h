#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <string>

class Description : public Information {
	private:
		std::string description;
	public:
		Description(std::string);
		virtual void setInfo(std::string s);
		virtual std::string getInfo();
};

#endif
