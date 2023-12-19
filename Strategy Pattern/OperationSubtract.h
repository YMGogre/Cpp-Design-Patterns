#ifndef OPERATIONSUBTRACT_H
#define OPERATIONSUBTRACT_H

#include "Strategy.h"

class OperationSubtract :
	public Strategy
{

public:
	inline virtual int doOperation(int num1, int num2) override {
		return num1 - num2;
	}
};

#endif // !OPERATIONSUBTRACT_H