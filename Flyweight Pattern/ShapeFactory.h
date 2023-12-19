#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <map>
#include <string>
#include <iostream>
#include "Shape.h"
#include "Circle.h"

/// <summary>
/// ��Ԫ�����࣬���ɻ��ڸ�����Ϣ��ʵ����Ķ���
/// </summary>
class ShapeFactory
{

private:
	static std::map<std::string, Shape*> circleMap;

public:
	/// <summary>
	/// ��ȡ����ɫ��ʶ�� Circle ����ָ�롣����ڴ��������򷵻��ڴ��е��Ǹ��������½�һ�� Circle ���󲢷�����ָ�롣
	/// </summary>
	/// <param name="_color">Բ�ε���ɫ</param>
	/// <returns>������Ԫ�� Shape ��ָ��</returns>
	static inline Shape* getCircle(std::string _color) {
		if (circleMap.find(_color) != circleMap.end()) {
			return circleMap[_color];
		}
		else {
			Shape* fly = new Circle(_color);
			circleMap.insert(std::pair<std::string, Shape*>(_color, fly));
			std::cout << "Creating circle of color : " << _color << std::endl;	// ���½�����ʱ��ӡ���
			return fly;
		}
	}
};

#endif // !SHAPEFACTORY_H