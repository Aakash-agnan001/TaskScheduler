#include "UID.h"

UID::UID()
{
	id = "0";
}

void UID::setID(string ident)
{
	id = ident;
}

string UID::getID()
{
	return id;
}
