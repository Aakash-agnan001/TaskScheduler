#include "Description.h"

Description::Description(std::string description) {
	this->description = description;
}

void Description::setDescription(std::string s) {
	description = s;
}

string Description::getDescription() {
	return description;
}
