#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>
#include <memory>
#include <iostream>

/// <summary>
/// ʵ�ֳ����� Shape ��ʵ��ԭ���� Rectangle
/// </summary>
class Rectangle :
	public Shape
{

private:
	std::string type;

public:
	Rectangle() : type("Rectangle") {}
	/// <summary>
	/// ʵ�ֻ���Ĵ����¡���������ڴ�������ĸ���
	/// </summary>
	/// <returns>������ Shape ������ָ��</returns>
	inline virtual std::unique_ptr<Shape> clone() const override {
		// ͨ���������죬���Ǵ�����һ���µ�ԭ�����ʵ����������һ��ָ������ָ�루����һ�������
		return std::make_unique<Rectangle>(*this);
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����Ⱦ����
	/// </summary>
	inline virtual void render() const override {
		std::cout << "Inside Rectangle::render() method." << std::endl;
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ����ȡ���ͺ���
	/// </summary>
	/// <returns>��������</returns>
	inline virtual std::string getType() const override {
		return type;
	}
};

#endif // !RECTANGLE_H