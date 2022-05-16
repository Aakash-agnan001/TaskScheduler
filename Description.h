#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <string>

class Description {
	private:
		std::string description;
	public:
		Description(std::string);
		void setDescription(std::string s);
		std::string getDescription();
};

#endif
