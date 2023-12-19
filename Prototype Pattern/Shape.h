#ifndef SHAPE_H
#define SHAPE_H

#include <memory>
#include <string>

/// <summary>
/// 抽象类 Shape
/// </summary>
class Shape
{

public:
	/// <summary>
	/// 纯虚克隆函数，用于创建对象的副本
	/// </summary>
	/// <returns>抽象类 Shape 的智能指针</returns>
	virtual std::unique_ptr<Shape> clone() const = 0;	// 有关 const 修饰成员函数，参考：<https://blog.csdn.net/YMGogre/article/details/126759839#t16>
	/// <summary>
	/// 纯虚渲染函数
	/// </summary>
	virtual void render() const = 0;
	/// <summary>
	/// 纯虚获取类型函数
	/// </summary>
	/// <returns></returns>
	virtual std::string getType() const = 0;
	virtual ~Shape() {}
};

#endif // !SHAPE_H