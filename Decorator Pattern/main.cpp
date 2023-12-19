#include "Ellipse.h"
#include "ShapeDecorator.h"
#include "RedBorderShapeDecorator.h"
#include "GreenBackgroundShapeDecorator.h"
#include <iostream>

int main() {
	Ellipse ellipse;
	RedBorderShapeDecorator redEllipse(ellipse);
	// 装饰器可嵌套包装装饰器
	GreenBackgroundShapeDecorator redGreenEllipse(redEllipse);

	std::cout << "Ellipse with normal border" << std::endl;
	ellipse.render();

	std::cout << "\nEllipse of red border" << std::endl;
	redEllipse.render();

	std::cout << "\nEllipse of red border and green background" << std::endl;
	redGreenEllipse.render();

	/**
	 * 请注意，main 函数中我们直接通过变量调用了成员函数，这意味着在 main 函数中
	 * 我们并没有使用 C++ 的多态特性。然而，这不影响我们展示装饰器模式。
	 * 装饰器模式的关键在于能够在不修改原有对象代码的情况下，为对象添加新的功能。
	 * 这是通过创建一个装饰器类来实现的，该类包装了原有对象，并提供了额外的行为。
	 */
}