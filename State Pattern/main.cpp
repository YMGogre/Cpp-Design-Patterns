#include "Context.h"
#include "StartState.h"
#include "StopState.h"
#include <iostream>

int main() {
	Context context;

	StartState startState;
	startState.doAction(context);
	std::cout << context.getState()->toString() << std::endl;

	StopState stopState;
	stopState.doAction(context);
	std::cout << context.getState()->toString() << std::endl;
}