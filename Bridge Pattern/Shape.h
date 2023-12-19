#ifndef SHAPE_H
#define SHAPE_H

#include "RenderAPI.h"

/// <summary>
/// 抽象类 Shape(抽象部分接口)
/// </summary>
class Shape
{

protected:
	RenderAPI* renderAPI;
	inline Shape(RenderAPI* _renderAPI) : renderAPI(_renderAPI) {}

public:
	/// <summary>
	/// 纯虚渲染函数
	/// </summary>
	virtual void render() = 0;
	virtual ~Shape() {
		delete renderAPI;
	}
	/** 是否要在析构中 `delete renderAPI; ` 取决于该指针的内存是否由 Shape 类负责创建和销毁的。
	  * 由于我们关注的重点是《设计模式》，所以不要太在意内存管理的问题。
	  * 一般我们只保留与设计模式相关的核心代码即可。
	  */
};

#endif // !SHAPE_H