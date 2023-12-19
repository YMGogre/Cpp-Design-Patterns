#include "ShapeCache.h"
#include <iostream>

int main() {
	ShapeCache cache;

	auto rectangle = cache.getShape("Rectangle");
	std::cout << "Shape: " << rectangle->getType() << std::endl;
	rectangle->render();

	auto ellipse = cache.getShape("Ellipse");
	std::cout << "\n\nShape: " << ellipse->getType() << std::endl;
	ellipse->render();
}