#ifndef STATICNESTEDCLASSSINGLETON_H
#define STATICNESTEDCLASSSINGLETON_H

/// <summary>
/// 静态内部类式单例模式类
/// </summary>
class StaticNestedClassSingleton {

private:
	StaticNestedClassSingleton() {}

	/// <summary>
	/// 截止到 2023 年，C++ 标准没有静态类的概念，但我们可以通过将所有成员声明为静态以达到类似静态类的效果
	/// </summary>
	class SingletonHolder {

	private:
		static const StaticNestedClassSingleton INSTANCE;
	public:
		static inline const StaticNestedClassSingleton& getInstance() {
			return INSTANCE;
		}
	};

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	StaticNestedClassSingleton(const StaticNestedClassSingleton&) = delete;					// 删除类的拷贝构造函数
	StaticNestedClassSingleton& operator=(const StaticNestedClassSingleton&) = delete;		// 删除类的拷贝赋值运算符

	/// <summary>
	/// 获取静态内部类的单例模式的唯一实例
	/// </summary>
	/// <returns>返回 StaticNestedClassSingleton 对象引用</returns>
	static inline const StaticNestedClassSingleton& getInstance() {
		return SingletonHolder::getInstance();
	}
};

#endif // !STATICNESTEDCLASSSINGLETON_H