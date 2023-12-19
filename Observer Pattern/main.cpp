#include "Subject.h"
#include "HexaObserver.h"
#include "OctalObserver.h"
#include "BinaryObserver.h"
#include <iostream>

int main() {
	Subject subject;

	HexaObserver ho(&subject);
	OctalObserver oo(&subject);
	BinaryObserver bo(&subject);

	std::cout << "First state change: 15" << std::endl;
	subject.setState(15);
	std::cout << "Second state change: 10" << std::endl;
	subject.setState(10);
}