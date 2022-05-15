#include "Description.h"

using namespace std;

Description::Description(string s) {
	description = s;
}

void Description::setDescription(string s) {
	description = s;
}

string Description::getDescription() {
	return description;
}
