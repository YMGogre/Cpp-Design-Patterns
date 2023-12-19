#ifndef GREENCIRCLE_H
#define GREENCIRCLE_H

#include "RenderAPI.h"
#include <iostream>

/// <summary>
/// 实现抽象类 RenderAPI 的实体类 GreenCircle(具体实现部分 2)
/// </summary>
class GreenCircle :
	public RenderAPI
{

public:
	/// <summary>
	/// 实现基类的纯虚渲染圆形函数
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="x">X 坐标</param>
	/// <param name="y">Y 坐标</param>
	inline virtual void renderCircle(int radius, int x, int y) override {
		std::cout << "Rendering Circle[ color: green, radius: "
			<< radius << ", x: " << x << ", y: " << y << "]" << std::endl;
	}
};

#endif // !GREENCIRCLE_H