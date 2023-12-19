#ifndef REDBORDERSHAPEDECORATOR_H
#define REDBORDERSHAPEDECORATOR_H

#include "ShapeDecorator.h"
#include <iostream>

/// <summary>
/// 继承自装饰器基类 ShapeDecorator 的具体装饰器类 RedBorderShapeDecorator
/// </summary>
class RedBorderShapeDecorator :
	public ShapeDecorator
{

private:
	/// <summary>
	/// 具体装饰器类添加了一个新的功能 —— 设置形状的红色边框
	/// </summary>
	/// <param name="decoratedShape">被装饰的 Shape 对象</param>
	inline void setRedBorder(Shape& decoratedShape) {
		std::cout << "Border Color: Red" << std::endl;
	}

public:
	inline RedBorderShapeDecorator(Shape& _decoratedShape) :
		ShapeDecorator(_decoratedShape) {
	}
	/// <summary>
	/// 重写基类的虚渲染函数并添加新的行为 —— 设置红色边框
	/// </summary>
	inline virtual void render() override {
		decoratedShape.render();
		setRedBorder(decoratedShape);
	}
};

#endif // !REDBORDERSHAPEDECORATOR_H