#ifndef STATICLOCALVARIABLESINGLETON_H
#define STATICLOCALVARIABLESINGLETON_H

/// <summary>
/// 静态局部变量式单例模式类（懒汉式的一种，C++ 标准保证了其是线程安全的）
/// </summary>
class StaticLocalVariableSingleton {

private:
	StaticLocalVariableSingleton() {};	// 私有构造函数

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	StaticLocalVariableSingleton(const StaticLocalVariableSingleton&) = delete;					// 删除类的拷贝构造函数
	StaticLocalVariableSingleton& operator=(const StaticLocalVariableSingleton&) = delete;		// 删除类的拷贝赋值运算符

	/// <summary>
	/// 获取静态局部变量式单例模式的唯一实例
	/// </summary>
	/// <returns>返回 StaticLocalVariableSingleton 的对象引用</returns>
	static inline StaticLocalVariableSingleton& getInstance() {
		static StaticLocalVariableSingleton instance;
		return instance;
	}
};

#endif // !STATICLOCALVARIABLESINGLETON_H