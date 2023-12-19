#ifndef ITERATOR_H
#define ITERATOR_H

#include "Container.h"

/// <summary>
/// 抽象迭代器
/// </summary>
/// <typeparam name="T">迭代器处理的类型</typeparam>
template <typename T>
class Iterator
{
protected:
	/// <summary>容器对象的引用</summary>
	Container<T>& container;
	/// <summary>项的索引</summary>
	size_t index = 0;

public:
	Iterator(Container<T>& _container) : container(_container) {}
	/// <summary>
	/// 纯虚拥有下一项函数
	/// </summary>
	/// <returns>返回 true 如果有下一项，否则返回 false</returns>
	virtual bool hasNext() = 0;
	/// <summary>
	/// 纯虚获取下一项函数
	/// </summary>
	/// <returns>集合中的下一项</returns>
	virtual T next() = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Iterator() {}
};

#endif // !ITERATOR_H