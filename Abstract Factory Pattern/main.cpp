#include "AbstractFactory.h"
#include "FactoryProducer.h"

int main() {
	// 获取形状工厂
	AbstractFactory* shapeFactory = FactoryProducer::getFactory("SHAPE");

	// 获取形状为 Rectangle 的对象
	Shape* shape1 = shapeFactory->getShape("Rectangle");

	// 调用 Rectangle 的 render() 方法
	shape1->render();

	// 获取形状为 Ellipse 的对象
	Shape* shape2 = shapeFactory->getShape("Ellipse");

	// 调用 Ellipse 的 render() 方法
	shape2->render();

	// 获取颜色工厂
	AbstractFactory* colorFactory = FactoryProducer::getFactory("COLOR");

	// 获取颜色为 Green 的对象
	Color* color1 = colorFactory->getColor("Green");

	// 调用 Green 的 fill() 方法
	color1->fill();

	// 获取颜色为 Blue 的对象
	Color* color2 = colorFactory->getColor("Blue");

	// 调用 Blue 的 fill() 方法
	color2->fill();
}