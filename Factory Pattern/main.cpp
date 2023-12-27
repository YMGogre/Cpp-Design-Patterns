#include "ShapeFactory.h"

int main() {
	ShapeFactory *shapeFactory = new ShapeFactory();

	// ��ȡ Rectangle ���󣬲��������� render() ����
	Shape* shape1 = shapeFactory->getShape("Rectangle");
	// ���� Rectangle �� render() ����
	shape1->render();

	// ��ȡ Ellipse ���󣬲��������� render() ����
	Shape* shape2 = shapeFactory->getShape("Ellipse");
	// ���� Ellipse �� render() ����
	shape2->render();

	delete shapeFactory;
	delete shape1;
	delete shape2;
}