#ifndef CALLONCESINGLETON_H
#define CALLONCESINGLETON_H

#include <memory>
#include <mutex>

/// <summary>
/// std::call_once 式单例模式类
/// </summary>
class CallOnceSingleton
{

private:
	static std::shared_ptr<CallOnceSingleton> instance;
	static std::once_flag singletonFlag;
	CallOnceSingleton() {}		// 私有构造函数

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	CallOnceSingleton(const CallOnceSingleton&) = delete;				// 删除类的拷贝构造函数
	CallOnceSingleton& operator=(const CallOnceSingleton&) = delete;	// 删除类的拷贝赋值运算符

	/// <summary>
	/// 获取 std::call_once 式单例模式的唯一实例
	/// </summary>
	/// <returns>返回 CallOnceSingleton 的智能指针</returns>
	static inline std::shared_ptr<CallOnceSingleton> getInstance() {
		std::call_once(singletonFlag, [&] {
			instance = std::shared_ptr<CallOnceSingleton>(new CallOnceSingleton());
		});
		return instance;
	}
};

#endif // !CALLONCESINGLETON_H