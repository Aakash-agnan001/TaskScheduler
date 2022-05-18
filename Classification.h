#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include "Information.hpp"

class Classification : public Information {
	private:
	unsigned int classification;

	public:
	virtual void setInfo(unsigned int);
	virtual unsigned int getInfo(unsigned int marker);
};

#endif
