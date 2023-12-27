#include "ShapeFactory.h"

int main() {
	ShapeFactory *shapeFactory = new ShapeFactory();

	// 获取 Rectangle 对象，并调用它的 render() 方法
	Shape* shape1 = shapeFactory->getShape("Rectangle");
	// 调用 Rectangle 的 render() 方法
	shape1->render();

	// 获取 Ellipse 对象，并调用它的 render() 方法
	Shape* shape2 = shapeFactory->getShape("Ellipse");
	// 调用 Ellipse 的 render() 方法
	shape2->render();

	delete shapeFactory;
	delete shape1;
	delete shape2;
}