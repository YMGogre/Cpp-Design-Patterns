#ifndef GREENBACKGROUNDSHAPEDECORATOR_H
#define GREENBACKGROUNDSHAPEDECORATOR_H

#include "ShapeDecorator.h"
#include <iostream>

/// <summary>
/// 继承自装饰器基类 ShapeDecorator 的具体装饰器类 GreenBackgroundShapeDecorator
/// </summary>
class GreenBackgroundShapeDecorator :
	public ShapeDecorator
{

private:
	/// <summary>
	/// 具体装饰器类添加了一个新的功能 —— 设置形状的绿色背景
	/// </summary>
	/// <param name="decoratedShape">被装饰的 Shape 对象</param>
	inline void setGreenBackground(Shape& decoratedShape) {
		std::cout << "Background Color: Green" << std::endl;
	}

public:
	inline GreenBackgroundShapeDecorator(Shape& _decoratedShape) :
		ShapeDecorator(_decoratedShape) {
	}
	/// <summary>
	/// 重写基类的虚渲染函数并添加新的行为 —— 设置绿色背景
	/// </summary>
	inline virtual void render() override {
		decoratedShape.render();
		setGreenBackground(decoratedShape);
	}
};

#endif // !GREENBACKGROUNDSHAPEDECORATOR_H