#include <cstring>
#include "FactoryProducer.h"

AbstractFactory* FactoryProducer::getFactory(const char* choice) {
	if (strcmp(choice, "SHAPE") == 0) {
		return new ShapeFactory();
	}
	else if (strcmp(choice, "COLOR") == 0) {
		return new ColorFactory();
	}
	return nullptr;
}