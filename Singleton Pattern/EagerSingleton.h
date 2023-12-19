#ifndef EAGERSINGLETON_H
#define EAGERSINGLETON_H

/// <summary>
/// 饿汉式单例模式类
/// </summary>
class EagerSingleton
{
private:
	static EagerSingleton instance;
	EagerSingleton() {};		// 私有构造函数

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	EagerSingleton(const EagerSingleton&) = delete;					// 删除类的拷贝构造函数
	EagerSingleton& operator=(const EagerSingleton&) = delete;		// 删除类的拷贝赋值运算符

	/// <summary>
	/// 获取饿汉式单例模式的唯一实例
	/// </summary>
	/// <returns>返回 EagerSingleton 的对象引用</returns>
	static inline EagerSingleton& getInstance() {
		return instance;
	}
};

#endif // !EAGERSINGLETON_H