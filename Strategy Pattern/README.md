[上一篇](../Template%20Pattern/README.md)

---

# 策略模式 Strategy

## 1、动机

* 在软件构建过程中，某些对象使用的算法可能多种多样，经常**改变**，如果将这些算法都编码到对象中，将会使对象变得异常复杂；而且有时候支持不使用的算法也是一个性能负担。
* 如何在运行时根据需要透明地更改对象的算法？将算法与对象本身解耦，从而避免上述问题？

> 在策略模式中一个类的行为或其算法可以在运行时更改。这种类型的设计模式属于行为型模式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>定义一系列的算法,把它们一个个封装起来, 并且使它们可相互替换。</dd>
    <dt>关键代码</dt>
    <dd>一系列的算法将实现同一个接口（抽象类）。</dd>
</dl>

---

## 3、实现

### 步骤一

我们将创建一个抽象的策略基类 Strategy。它包含一个纯虚的成员函数 `doOperation(int num1, int num2)`，该成员函数将会提供对两个操作数「执行操作」的一系列的算法；但算法的实现将会推迟到派生类中进行。

我们的 Strategy 类如下：

```cpp
class Strategy
{

public:
	virtual int doOperation(int num1, int num2) = 0;
	virtual ~Strategy() {}
};
```

### 步骤二

接下来我们创建实现了 Strategy 接口的实体类 OperationAdd、OperationSubtract 和 OperationMultiply。它们将分别实现「两数相加」、「两数相减」和「两数相乘」的对两个操作数「执行操作」的算法：

```cpp
// 两数相加
class OperationAdd :
	public Strategy
{

public:
	inline virtual int doOperation(int num1, int num2) override {
		return num1 + num2;
	}
};

// 两数相减
class OperationSubtract :
	public Strategy
{

public:
	inline virtual int doOperation(int num1, int num2) override {
		return num1 - num2;
	}
};

// 两数相乘
class OperationMultiply :
	public Strategy
{

public:
	inline virtual int doOperation(int num1, int num2) override {
		return num1 * num2;
	}
};
```

### 步骤三

接下来我们需要创建一个 Context 上下文类，该类是一个使用了某种策略的类。Context 类可在运行时根据需要透明地更改对象的算法。

我们的 Context 类如下：

```cpp
class Context
{

private:
	Strategy* strategy;

public:
	Context(Strategy* _strategy) : strategy(_strategy) {}
	inline int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
	~Context() {
		delete strategy;
	}
};
```

Context 类拥有一个私有的 Strategy 类的指针成员变量 strategy。当我们在成员函数 `executeStrategy(int num1, int num2)` 中使用该指针成员变量调用 `doOperation(int num1, int num2)` 方法时，我们知道对该函数的调用将具备多态特性。

### 步骤四

在 `main()` 函数中，我们使用 Context 来查看当它改变策略 Strategy 时的行为变化：

```cpp
int main() {
	Context context1(new OperationAdd());
	std::cout << "10 + 5 = " << context1.executeStrategy(10, 5) << std::endl;
	Context context2(new OperationSubtract());
	std::cout << "10 - 5 = " << context2.executeStrategy(10, 5) << std::endl;
	Context context3(new OperationMultiply());
	std::cout << "10 * 5 = " << context3.executeStrategy(10, 5) << std::endl;
}
```

> 在 `main()` 函数中，我们为每个操作创建了一个新的 Context 对象，而并没有在运行时改变单个 Context 对象的行为。每个 Context 对象在创建时就已经确定了其策略（即行为），并且在其生命周期内，这个策略是不会改变的。
>
> 然而，这并不意味着我们不能在运行时改变单个 Context 对象的行为。事实上，如果我们希望在运行时改变单个 Context 对象的行为，我们可以在 Context 类中添加一个设置策略的方法，比如：
> ```cpp
> inline void setStrategy(Strategy* _strategy) {
> 	delete strategy;
> 	strategy = _strategy;
> }
> ```
> 然后，我们就可以在运行时改变单个 Context 对象的行为了。

### 步骤五

执行程序，输出结果：

```plain
10 + 5 = 15
10 - 5 = 5
10 * 5 = 50
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 策略及其派生类为组件提供了一系列可重用的算法，从而可以使得类型在运行时方便地根据需要在各个算法之间进行切换。
* 策略模式提供了用条件判断语句以外的另一种选择，消除条件判断语句，就是在解耦合。含有许多条件判断语句的代码通常都需要策略模式。
* 如果策略对象没有实例变量，那么各个上下文可以共享同一个策略对象，从而节省对象开销。

	> 当然，共享策略对象意味着我们需要小心内存管理问题，因为 Context 类的析构会删除其持有的 Strategy 对象。如果多个 Context 对象共享同一个 Strategy 对象，那么当其中一个 Context 对象被销毁时，它会删除 Strategy 对象，这将导致其他 Context 对象持有一个已经被删除的对象的指针，这将导致未定义的行为。
	>
	> 此时，使用智能指针将是不错的解决方案（比如 `std::shared_ptr`）。

---

[下一篇](../Observer%20Pattern/README.md)