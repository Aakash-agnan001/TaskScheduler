#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <string>
#include "Information.hpp"

class Description : public Information {
	private:
		std::string description;
	public:
		Description(std::string);
		virtual void setInfo(std::string s);
		virtual std::string getInfo(std::string);
};

#endif
