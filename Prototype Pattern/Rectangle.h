#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>
#include <memory>
#include <iostream>

/// <summary>
/// 实现抽象类 Shape 的实体原型类 Rectangle
/// </summary>
class Rectangle :
	public Shape
{

private:
	std::string type;

public:
	Rectangle() : type("Rectangle") {}
	/// <summary>
	/// 实现基类的纯虚克隆函数，用于创建对象的副本
	/// </summary>
	/// <returns>抽象类 Shape 的智能指针</returns>
	inline virtual std::unique_ptr<Shape> clone() const override {
		// 通过拷贝构造，我们创建了一个新的原型类的实例，并返回一个指向它的指针（发生一次深拷贝）
		return std::make_unique<Rectangle>(*this);
	}
	/// <summary>
	/// 实现基类的纯虚渲染函数
	/// </summary>
	inline virtual void render() const override {
		std::cout << "Inside Rectangle::render() method." << std::endl;
	}
	/// <summary>
	/// 实现基类的纯虚获取类型函数
	/// </summary>
	/// <returns>类型名称</returns>
	inline virtual std::string getType() const override {
		return type;
	}
};

#endif // !RECTANGLE_H