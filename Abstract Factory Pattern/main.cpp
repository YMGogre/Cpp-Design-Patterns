#include "AbstractFactory.h"
#include "FactoryProducer.h"

int main() {
	// ��ȡ��״����
	AbstractFactory* shapeFactory = FactoryProducer::getFactory("SHAPE");

	// ��ȡ��״Ϊ Rectangle �Ķ���
	Shape* shape1 = shapeFactory->getShape("Rectangle");

	// ���� Rectangle �� render() ����
	shape1->render();

	// ��ȡ��״Ϊ Ellipse �Ķ���
	Shape* shape2 = shapeFactory->getShape("Ellipse");

	// ���� Ellipse �� render() ����
	shape2->render();

	// ��ȡ��ɫ����
	AbstractFactory* colorFactory = FactoryProducer::getFactory("COLOR");

	// ��ȡ��ɫΪ Green �Ķ���
	Color* color1 = colorFactory->getColor("Green");

	// ���� Green �� fill() ����
	color1->fill();

	// ��ȡ��ɫΪ Blue �Ķ���
	Color* color2 = colorFactory->getColor("Blue");

	// ���� Blue �� fill() ����
	color2->fill();
}