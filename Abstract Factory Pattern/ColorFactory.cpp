#include <cstring>
#include "ColorFactory.h"

Shape* ColorFactory::getShape(const char* shapeType) {
	return nullptr;
}

Color* ColorFactory::getColor(const char* colorType) {
	if (colorType == nullptr) {
		return nullptr;
	}
	if (strcmp(colorType, "Green") == 0) {
		return new Green();
	}
	else if (strcmp(colorType, "Blue") == 0) {
		return new Blue();
	}
	return nullptr;
}