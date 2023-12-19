#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include "Shape.h"

/// <summary>
/// 实现抽象类 Shape 的实体装饰器基类 ShapeDecorator（通过构造函数的访问限制该类在外界被实例化）
/// </summary>
class ShapeDecorator :
	public Shape
{

protected:
	/// <summary>被装饰的 Shape 对象</summary>
	Shape& decoratedShape;
	/// <summary>
	/// 受保护的构造函数以避免被外界实例化
	/// </summary>
	/// <param name="_decoratedShape">被装饰的 Shape 对象</param>
	inline ShapeDecorator(Shape& _decoratedShape) :
		decoratedShape(_decoratedShape) {
	}

public:
	/// <summary>
	/// 实现基类的纯虚渲染函数
	/// </summary>
	inline virtual void render() override {
		decoratedShape.render();
	}
};

#endif // !SHAPEDECORATOR_H