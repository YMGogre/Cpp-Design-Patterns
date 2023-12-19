#include "Circle.h"
#include "ShapeFactory.h"
#include <string>
#include <random>

std::string colors[] = { "Red", "Green", "Blue", "White", "Black" };
std::map<std::string, Shape*> ShapeFactory::circleMap;	// ���徲̬��Ա����
std::random_device rd;		// ���ڻ�ȡ��������豸
std::default_random_engine eng(rd());	// ���������
std::uniform_real_distribution<double> distr1(0, 1);	// [0, 1) �뿪������ȷֲ��������������<https://zh.cppreference.com/w/cpp/numeric/random/uniform_real_distribution>
std::uniform_int_distribution<int> distr2(1, 100);		// [1, 100] ��������ȷֲ��������������<https://zh.cppreference.com/w/cpp/numeric/random/uniform_int_distribution>

std::string getRandomColor();
int getRandomX();
int getRandomY();

int main() {
	for (int i = 0; i < 20; i++) {
		auto circle = static_cast<Circle*>(ShapeFactory::getCircle(getRandomColor()));
		circle->setX(getRandomX());
		circle->setY(getRandomY());
		circle->setRadius(100);
		circle->render();
	}
}

std::string getRandomColor() {
	auto length = sizeof(colors) / sizeof(colors[0]);
	return colors[(int)(distr1(eng) * length)];
}
int getRandomX() {
	return distr2(eng);
}
int getRandomY() {
	return distr2(eng);
}