#include "EagerSingleton.h"
#include "ThreadSafeLazySingleton.h"
#include "ThreadUnsafeLazySingleton.h"
#include "DoubleCheckedLockingSingleton.h"
#include "ThreadSafeDoubleCheckedLockingSingleton.h"
#include "StaticNestedClassSingleton.h"
#include "StaticLocalVariableSingleton.h"
#include "CallOnceSingleton.h"
#include <memory>
#include <mutex>
#include <iostream>

/** ��ĳ��.cpp �ļ������� main.cpp���ж������е���ľ�̬��Ա������
  * Q��Ϊ�β��� .h ͷ�ļ��ж����أ�
  *		A����Ϊ��̬��Ա���������ڳ�����ֻ��һ�����塣�������̬��Ա�����Ķ������ͷ�ļ��У������ .cpp �ļ�����ͬһ��ͷ�ļ�ʱ��
  *		   �ᵼ�¾�̬��Ա�����������Σ��Ӷ�������multiple definition�����󡣲ο���https://blog.csdn.net/YMGogre/article/details/126759839#t3
  */

EagerSingleton EagerSingleton::instance;
ThreadSafeLazySingleton* ThreadSafeLazySingleton::instance = nullptr;
std::mutex ThreadSafeLazySingleton::mutex;
ThreadUnsafeLazySingleton* ThreadUnsafeLazySingleton::instance = nullptr;
DoubleCheckedLockingSingleton* DoubleCheckedLockingSingleton::instance = nullptr;
std::mutex DoubleCheckedLockingSingleton::mutex;
std::atomic<ThreadSafeDoubleCheckedLockingSingleton*> ThreadSafeDoubleCheckedLockingSingleton::instance;
std::mutex ThreadSafeDoubleCheckedLockingSingleton::mutex;
const StaticNestedClassSingleton StaticNestedClassSingleton::SingletonHolder::INSTANCE;
std::shared_ptr<CallOnceSingleton> CallOnceSingleton::instance;
std::once_flag CallOnceSingleton::singletonFlag;

int main() {
	EagerSingleton& instance1 = EagerSingleton::getInstance();
	ThreadSafeLazySingleton* instance2 = ThreadSafeLazySingleton::getInstance();
	ThreadUnsafeLazySingleton* instance3 = ThreadUnsafeLazySingleton::getInstance();
	DoubleCheckedLockingSingleton* instance4 = DoubleCheckedLockingSingleton::getInstance();
	ThreadSafeDoubleCheckedLockingSingleton* instance5 = ThreadSafeDoubleCheckedLockingSingleton::getInstance();
	const StaticNestedClassSingleton& instance6 = StaticNestedClassSingleton::getInstance();
	StaticLocalVariableSingleton& instance7 = StaticLocalVariableSingleton::getInstance();
	std::shared_ptr<CallOnceSingleton> instance8 = CallOnceSingleton::getInstance();

	std::cout << "�Ѵ������ֵ���ģʽ��Ψһʵ��" << std::endl;
}