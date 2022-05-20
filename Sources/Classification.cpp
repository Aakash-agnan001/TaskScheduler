#include "../Headers/Classification.h"

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

