#include "Classification.h"

Classification::Classification()
{
	classification = 0;
}

void Classification::setInfo(unsigned int clas)
{
	classification = clas;
}

unsigned int Classification::getInfo(unsigned int marker)
{
	return classification;
}

