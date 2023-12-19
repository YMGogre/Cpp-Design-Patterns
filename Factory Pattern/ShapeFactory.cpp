#include <cstring>
#include "ShapeFactory.h"

Shape* ShapeFactory::getShape(const char* shapeType) {
	if (shapeType == nullptr) {
		return nullptr;
	}
	if (strcmp(shapeType, "Rectangle") == 0) {
		return new Rectangle();
	}
	else if (strcmp(shapeType, "Ellipse") == 0) {
		return new Ellipse();
	}
	return nullptr;
}