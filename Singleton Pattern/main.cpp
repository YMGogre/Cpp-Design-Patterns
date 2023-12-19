#include "EagerSingleton.h"
#include "ThreadSafeLazySingleton.h"
#include "ThreadUnsafeLazySingleton.h"
#include "DoubleCheckedLockingSingleton.h"
#include "StaticNestedClassSingleton.h"
#include "StaticLocalVariableSingleton.h"
#include <iostream>

/** 在某个.cpp 文件（比如 main.cpp）中定义所有的类的静态成员变量。
  * Q：为何不在 .h 头文件中定义呢？
  *		A：因为静态成员变量必须在程序中只有一个定义。如果将静态成员变量的定义放在头文件中，当多个 .cpp 文件包含同一个头文件时，
  *		   会导致静态成员变量被定义多次，从而引发“multiple definition”错误。参考：https://blog.csdn.net/YMGogre/article/details/126759839#t3
  */

EagerSingleton EagerSingleton::instance;
ThreadSafeLazySingleton* ThreadSafeLazySingleton::instance = nullptr;
std::mutex ThreadSafeLazySingleton::mutex;
ThreadUnsafeLazySingleton* ThreadUnsafeLazySingleton::instance = nullptr;
DoubleCheckedLockingSingleton* DoubleCheckedLockingSingleton::instance = nullptr;
std::mutex DoubleCheckedLockingSingleton::mutex;
const StaticNestedClassSingleton StaticNestedClassSingleton::SingletonHolder::INSTANCE;

int main() {
	EagerSingleton& instance1 = EagerSingleton::getInstance();
	ThreadSafeLazySingleton* instance2 = ThreadSafeLazySingleton::getInstance();
	ThreadUnsafeLazySingleton* instance3 = ThreadUnsafeLazySingleton::getInstance();
	DoubleCheckedLockingSingleton* instance4 = DoubleCheckedLockingSingleton::getInstance();
	const StaticNestedClassSingleton& instance5 = StaticNestedClassSingleton::getInstance();
	StaticLocalVariableSingleton& instance6 = StaticLocalVariableSingleton::getInstance();

	std::cout << "已创建各种单例模式的唯一实例" << std::endl;
}