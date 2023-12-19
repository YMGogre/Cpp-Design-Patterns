#ifndef SHAPE_H
#define SHAPE_H

/// <summary>
/// 抽象享元类 Shape
/// </summary>
class Shape {
public:
	/// <summary>
	/// 纯虚渲染函数
	/// </summary>
	virtual void render() = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Shape() {};
};

#endif // !SHAPE_H