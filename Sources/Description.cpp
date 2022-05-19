#include "../Headers/Description.h"

Description::Description(std::string s) {
	description = s;
}

void Description::setInfo(std::string s) {
	description = s;
}

std::string Description::getInfo(std::string marker) {
	return description;
}
