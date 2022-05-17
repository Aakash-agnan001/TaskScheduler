#include "UID.h"

UID::UID(string user)
{
	id = user;
}

void UID::setInfo(string ident)
{
	id = ident;
}

string UID::getInfo()
{
	return id;
}
