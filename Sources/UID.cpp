#include "../Headers/UID.h"

UID::UID(std::string user)
{
	id = user;
}

void UID::setInfo(std::string ident)
{
	id = ident;
}

std::string UID::getInfo(std::string marker)
{
	return id;
}
