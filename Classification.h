#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

using namespace std;

#include "Information.hpp"

class Classification : public Information {
	private:
	int classification;

	public:
	virtual void setInfo(int cla);
	virtual int getInfo();
}

#endif
