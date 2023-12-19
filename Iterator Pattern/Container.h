#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <memory>

template <typename T>
class Iterator;		// 使用前向声明以避免循环依赖

/// <summary>
/// 抽象容器
/// </summary>
/// <typeparam name="T">容器元素类型</typeparam>
template <typename T>
class Container
{
protected:
	/// <summary>项的集合</summary>
	std::vector<T> items;

public:
	Container(const std::vector<T>& init_vec) : items(init_vec) {}
	/// <summary>
	/// 纯虚获取迭代器函数
	/// </summary>
	/// <returns>迭代器智能指针</returns>
	virtual std::unique_ptr<Iterator<T>> getIterator() = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Container() {}
	/// <summary>
	/// 获取容器的大小
	/// </summary>
	/// <returns>容器包含项的个数</returns>
	inline size_t size() const { return items.size(); }
	/// <summary>
	/// 重载 [] 运算符
	/// </summary>
	/// <param name="index">索引下标</param>
	/// <returns>容器中指定索引的项</returns>
	inline T& operator[](int index){ return items[index]; }
};

#endif // !CONTAINER_H