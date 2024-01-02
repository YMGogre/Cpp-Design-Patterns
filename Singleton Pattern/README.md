[上一篇](../Builder%20Pattern/README.md)

---

# 💠 “对象性能”模式

面向对象很好地解决了 “抽象” 的问题，但是必不可免地要付出一定的代价。对于通常情况来讲，面向对象的成本大都可以忽略不计。但是某些情况，面向对象所带来的成本必须谨慎处理。

典型模式：
* 单例模式 Singleton
* 享元模式 Flyweight

# 单例模式 Singleton

## 1、动机

* 在软件系统中，经常有这样一些特殊的类，必须保证它们在系统中只存在一个实例，才能确保它们的逻辑正确性、以及良好的效率。
* 如何绕开常规的构造器，提供一种机制来保证一个类只有一个实例？
* 这应该是类设计者的责任，而不是使用者的责任。

> 单例模式是最简单的设计模式之一。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>保证一个类仅有一个实例，并提供一个访问它的全局访问点。</dd>
    <dt>关键代码</dt>
    <dd>构造函数是私有的。</dd>
</dl>

---

## 3、实现

### 懒汉式，线程不安全单例模式实现

* 是否 Lazy 初始化：是
* 是否多线程安全：否
* 实现难度：易
* 描述：基本的实现方式，最大的问题是线程不安全。

```cpp
class ThreadUnsafeLazySingleton {

private:
	static ThreadUnsafeLazySingleton* instance;
	ThreadUnsafeLazySingleton() {}

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	ThreadUnsafeLazySingleton(const ThreadUnsafeLazySingleton&) = delete;
	ThreadUnsafeLazySingleton& operator=(const ThreadUnsafeLazySingleton&) = delete;

	static inline ThreadUnsafeLazySingleton* getInstance() {
		if (instance == nullptr) {
			instance = new ThreadUnsafeLazySingleton();
		}
		return instance;
	}
};

ThreadUnsafeLazySingleton* ThreadUnsafeLazySingleton::instance = nullptr;
```

> ThreadUnsafeLazySingleton 类提供了 `getInstance()` 静态成员函数以获取唯一实例。但该实现在多线程环境下并不安全。
> 
> 此外，ThreadUnsafeLazySingleton 是在第一次被使用时才实例化，也就是延迟加载，顾名 “懒汉” 嘛。

### 饿汉式单例模式实现

* 是否 Lazy 初始化：否
* 是否多线程安全：是
* 实现难度：易
* 描述：基本的实现方式，也比较常用，但容易产生垃圾对象（无论程序是否使用唯一实例，其都会被创建）。

```cpp
class EagerSingleton
{
private:
	static EagerSingleton instance;
	EagerSingleton() {};

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	EagerSingleton(const EagerSingleton&) = delete;
	EagerSingleton& operator=(const EagerSingleton&) = delete;

	static inline EagerSingleton& getInstance() {
		return instance;
	}
};

EagerSingleton EagerSingleton::instance;
```

> 在 C++ 中，静态成员变量会在程序开始运行时（也就是 `main()` 函数执行之前）就进行初始化。所以饿汉式单例模式的唯一实例在程序启动时就已经创建，无需考虑多线程问题。

💬 此外，还有一些单例模式实现，请直接参考源码：

### [懒汉式，线程安全](./ThreadSafeLazySingleton.h)

* 是否 Lazy 初始化：是
* 是否多线程安全：是
* 实现难度：易
* 描述：在[线程不安全懒汉式](#懒汉式线程不安全单例模式实现)基础上通过锁的机制以确保线程安全；但锁的代价过高会导致效率较低。

### [双检锁/双重校验锁（DCL）](./DoubleCheckedLockingSingleton.h)

* 是否 Lazy 初始化：是
* 是否多线程安全：是（可能否）
* 实现难度：较复杂
* 描述：采用双检锁机制，安全且在多线程环境下能保持高性能。⚠️ 但双检锁可能会出现[内存读写 reorder 不安全问题](https://zhuanlan.zhihu.com/p/62014096)。所以不推荐。

### [双检锁，线程安全](./ThreadSafeDoubleCheckedLockingSingleton.h)

* 是否 Lazy 初始化：是
* 是否多线程安全：是
* 实现难度：复杂
* 描述：为了解决双检锁可能出现的内存读写 reorder 不安全问题，在 C++11 之后我们可以实现线程安全的双检锁。

### [登记式/静态内部类](./StaticNestedClassSingleton.h)

* 是否 Lazy 初始化：是
* 是否多线程安全：是
* 实现难度：一般
* 描述：在 C++ 中，我们通常不使用登记式/静态内部类的方式来实现单例模式。这主要是因为 C++ 的语言特性与 Java 不同：Java 能够保证静态内部类的线程安全和延迟加载；而 C++ 中没有这样的语言特性支持。

### [静态局部变量](./StaticLocalVariableSingleton.h)

* 是否 Lazy 初始化：是
* 是否多线程安全：C++11 线程安全
* 实现难度：易
* 描述：⭐ C++ 单例模式的经典实现方式，推荐使用。在 C++11 标准下，静态局部变量的初始化是线程安全的，不需要额外加锁保证线程安全性。

### [std::call_once 式](./CallOnceSingleton.h)

* 是否 Lazy 初始化：是
* 是否多线程安全：C++11 线程安全
* 实现难度：一般
* 描述：使用 [std::call_once](https://zh.cppreference.com/w/cpp/thread/call_once) 和 [std::once_flag](https://zh.cppreference.com/w/cpp/thread/once_flag) 使得函数可以线程安全地只调用一次。

---

## 4、总结

* 以上每种方式都有其适用的场景和优缺点，选择哪种方式取决于具体的需求和环境。例如，如果你的代码需要在多线程环境中运行，那么你应该选择一种线程安全的实现方式。如果你的单例对象的构造函数非常耗时，那么懒汉式可能是一个更好的选择，因为它可以延迟对象的创建，直到真正需要的时候才创建对象。相反，如果你的单例对象的构造函数非常快，或者你的代码总是需要立即使用单例对象，那么饿汉式可能是一个更好的选择，因为它可以在程序启动时就立即创建对象。
* 单例模式中的实例构造器（构造函数）可以设置为 `protected` 以允许子类派生。
* 单例模式一般不要支持拷贝构造和 Clone 接口（参考本文任意一个实现方式的源码即可），因为这有可能导致多个对象实例，与单例模式的初衷违背。

---

[下一篇](../Flyweight%20Pattern/README.md)