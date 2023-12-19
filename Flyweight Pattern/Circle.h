#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>
#include <iostream>

/// <summary>
/// 实现抽象类 Shape 的具体享元类 Circle
/// </summary>
class Circle :
	public Shape
{

private:
	std::string color;
	int x = 0;
	int y = 0;
	int radius = 0;

public:
	inline Circle(std::string _color) : color(_color) {};

	inline void setX(int _x) {
		x = _x;
	}
	inline void setY(int _y) {
		y = _y;
	}
	inline void setRadius(int _radius) {
		radius = _radius;
	}
	/// <summary>
	/// 实现基类的纯虚渲染函数
	/// </summary>
	inline virtual void render() override{
		std::cout << "Circle: Render() [Color : " << color << ", x : "
			<< x << ", y : " << y << ", radius : " << radius << "]" <<std::endl;
	}
};

#endif // !CIRCLE_H