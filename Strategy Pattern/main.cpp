#include "Context.h"
#include "OperationAdd.h"
#include "OperationSubtract.h"
#include "OperationMultiply.h"
#include <iostream>

int main() {
	Context context1(new OperationAdd());
	std::cout << "10 + 5 = " << context1.executeStrategy(10, 5) << std::endl;
	Context context2(new OperationSubtract());
	std::cout << "10 - 5 = " << context2.executeStrategy(10, 5) << std::endl;
	Context context3(new OperationMultiply());
	std::cout << "10 * 5 = " << context3.executeStrategy(10, 5) << std::endl;
}