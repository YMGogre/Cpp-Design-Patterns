#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "RenderAPI.h"

/// <summary>
/// 实现抽象类 Shape 的实体类 Circle(具体抽象部分)
/// </summary>
class Circle :
	public Shape
{

private:
	int x, y, radius;

public:
	inline Circle(int _x, int _y, int _radius, RenderAPI* _renderAPI) :
		Shape(_renderAPI), x(_x), y(_y), radius(_radius) {
	}
	/// <summary>
	/// 实现基类的纯虚渲染函数
	/// </summary>
	inline virtual void render() override {
		renderAPI->renderCircle(radius, x, y);
	}
};

#endif // !CIRCLE_H