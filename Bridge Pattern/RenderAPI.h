#ifndef RENDERAPI_H
#define RENDERAPI_H

/// <summary>
/// 抽象类 RenderAPI(实现部分接口)
/// </summary>
class RenderAPI
{

public:
	/// <summary>
	/// 纯虚渲染圆形函数
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="x">X 坐标</param>
	/// <param name="y">Y 坐标</param>
	virtual void renderCircle(int radius, int x, int y) = 0;
	virtual ~RenderAPI() {}
};

#endif // !RENDERAPI_H