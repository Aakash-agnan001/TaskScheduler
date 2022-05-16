#include "Description.h"

Description::Description(std::string s) {
	description = s;
}

void Description::setDescription(std::string s) {
	description = s;
}

std::string Description::getDescription() {
	return description;
}
