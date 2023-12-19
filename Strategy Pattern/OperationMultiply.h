#ifndef OPERATIONMULTIPLY_H
#define OPERATIONMULTIPLY_H

#include "Strategy.h"

class OperationMultiply :
	public Strategy
{

public:
	inline virtual int doOperation(int num1, int num2) override {
		return num1 * num2;
	}
};

#endif // !OPERATIONMULTIPLY_H