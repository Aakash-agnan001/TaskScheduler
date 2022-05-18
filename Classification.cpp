#include "Classification.h"

Classification::Classification()
{
	this->classification = 0;
}

Classification::Classification(unsigned classification)
{
	this->classification = classification;
}

void Classification::setInfo(unsigned clas)
{
	this->classification = clas;
}

unsigned int Classification::getInfo(unsigned marker)
{
	return this->classification;
}

