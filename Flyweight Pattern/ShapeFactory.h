#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <map>
#include <string>
#include <iostream>
#include "Shape.h"
#include "Circle.h"

/// <summary>
/// 享元工厂类，生成基于给定信息的实体类的对象
/// </summary>
class ShapeFactory
{

private:
	static std::map<std::string, Shape*> circleMap;

public:
	/// <summary>
	/// 获取由颜色标识的 Circle 对象指针。如果内存中已有则返回内存中的那个；否则新建一个 Circle 对象并返回其指针。
	/// </summary>
	/// <param name="_color">圆形的颜色</param>
	/// <returns>抽象享元类 Shape 的指针</returns>
	static inline Shape* getCircle(std::string _color) {
		if (circleMap.find(_color) != circleMap.end()) {
			return circleMap[_color];
		}
		else {
			Shape* fly = new Circle(_color);
			circleMap.insert(std::pair<std::string, Shape*>(_color, fly));
			std::cout << "Creating circle of color : " << _color << std::endl;	// 在新建对象时打印输出
			return fly;
		}
	}
};

#endif // !SHAPEFACTORY_H