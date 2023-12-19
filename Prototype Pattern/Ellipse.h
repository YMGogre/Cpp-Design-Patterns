#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include <string>
#include <memory>
#include <iostream>

/// <summary>
/// ʵ�ֳ����� Shape ��ʵ��ԭ���� Ellipse
/// </summary>
class Ellipse :
	public Shape
{

private:
	std::string type;

public:
	Ellipse() : type("Ellipse") {}
	/// <summary>
	/// ʵ�ֻ���Ĵ����¡���������ڴ�������ĸ���
	/// </summary>
	/// <returns>������ Shape ������ָ��</returns>
	inline virtual std::unique_ptr<Shape> clone() const override {
		// ͨ���������죬���Ǵ�����һ���µ�ԭ�����ʵ����������һ��ָ������ָ�루����һ�������
		return std::make_unique<Ellipse>(*this);
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����Ⱦ����
	/// </summary>
	inline virtual void render() const override {
		std::cout << "Inside Ellipse::render() method." << std::endl;
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ����ȡ���ͺ���
	/// </summary>
	/// <returns>��������</returns>
	inline virtual std::string getType() const override {
		return type;
	}
};

#endif // !ELLIPSE_H