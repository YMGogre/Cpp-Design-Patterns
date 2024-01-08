[上一篇](../Mediator%20Pattern/README.md)

---

# 💠 “状态变化”模式

在组件构建过程中，某些对象的状态经常面临变化，如何对这些变化进行有效的管理？同时又维持高层模块的稳定？“状态变化” 模式为这一问题提供了一种解决方案。

典型模式：
* 状态模式 State
* 备忘录模式 Memento

# 状态模式 State

## 1、动机

* 在软件构建过程中，某些对象的状态如果改变，其行为也会随之而发生变化。比如文档处于只读状态，其支持的行为和读写状态支持的行为就可能完全不同。
* 如何在运行时根据对象的状态来透明地更改对象的行为？为不会为对象操作和状态转化之间引入紧耦合？

> 在状态模式中，类的行为是基于它的状态改变的。这种类型的设计模式属于行为型模式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>允许对象在内部状态发生改变时改变它的行为，对象看起来好像修改了它的类。</dd>
    <dt>关键代码</dt>
    <dd>在没有使用状态模式的时候，我们的状态变量可能是个枚举值，在应用时我们可能需要判断对象的状态并进行不同的操作，这可能需要使用大量的 <code>if-else</code> 语句，显然这违背了开闭原则。<br>借助面向对象的抽象思维，我们可以将状态声明为一个接口，并且一系列的具体状态将实现该接口；同时我们将不同状态对应的不同操作全部转换为状态对象的行为（成员函数），操作不再是由拥有状态的对象负责，而是由状态对象本身负责。</dd>
</dl>

---

## 3、实现

我们将创建一个状态接口 State 和实现了该接口的实体状态类。我们还将创建一个上下文类 Context，其带有某种状态（通过对象组合的方式）。

### 步骤一

首先我们创建一个状态接口 State：

```cpp
class State
{

public:
	virtual void doAction(Context& context) = 0;
	virtual std::string toString() = 0;
	virtual ~State() {}
};
```

> State 包含一些纯虚成员函数。其中：
> * `doAction(Context& context)`：用于执行动作的函数。其中参数需要传递一个 Context 上下文对象的引用，用于执行指定状态的操作并在原对象上设置状态。
> * `toString()`：将对象转换为字符串，在需要打印或显示对象信息时使用。

### 步骤二

接下来创建实现了 State 类的实体状态类 StartState 和 StopState。它们将重写抽象类的方法以实现在不同状态下执行不同的操作并设置 Context 上下文对象的状态：

```cpp
class StartState :
	public State
{

public:
	inline virtual void doAction(Context& context) override {
		std::cout << "Player is in start state" << std::endl;
		context.setState(this);
	}

	inline virtual std::string toString() override {
		return "Start State";
	}
};
```

```cpp
class StopState :
	public State
{

public:
	inline virtual void doAction(Context& context) override {
		std::cout << "Player is in stop state" << std::endl;
		context.setState(this);
	}

	inline virtual std::string toString() override {
		return "Stop State";
	}
};
```

> 这里我们的策略是在 `doAction(Context& context)` 函数内将 Context 对象的状态设置为当前状态对象；当然我们也可以选择其他策略（比如将 Context 对象的状态设置为后继状态对象，这样可以实现状态的有序变化。我们可以为 StartState 和 StopState 新增一个字段 `private State* nextState;` 来引用后继状态对象）。

### 步骤三

接下来我们创建上下文 Context 类，其带有某种状态：

```cpp
class Context
{
	
private:
	State* state = nullptr;

public:
	Context() = default;	
	Context(State* _state) : state(_state) {}
	inline void setState(State* _state) {
		state = _state;
	}
	inline State* getState() {
		return state;
	}
};
```

> 有关 `default` 关键字用法，可参考[这里](https://stackoverflow.com/questions/6502828/what-does-default-mean-after-a-class-function-declaration)。

### 步骤四

在 `main()` 函数中，我们使用 Context 来查看当状态 State 改变时的行为变化：

```cpp
int main() {
	Context context;

	StartState startState;
	startState.doAction(context);
	std::cout << context.getState()->toString() << std::endl;

	StopState stopState;
	stopState.doAction(context);
	std::cout << context.getState()->toString() << std::endl;
}
```

### 步骤五

执行程序，输出结果：

```plain
Player is in start state
Start State
Player is in stop state
Stop State
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 状态模式解决问题的思路有些类似于[策略模式](../Strategy%20Pattern/README.md)。
* 状态模式将所有与一个特定状态相关的行为都放入一个 State 的子类对象中。在对象状态切换时，切换相应的对象；但同时维持 State 的接口，这样实现了具体操作与状态转换之间的解耦。
* 为不同的状态引入不同的对象使得状态转换变得更加明确，而且可以保证不会出现状态不一致的情况，因为转换是原子性的 —— 即要么彻底转换过来，要么不转换。
* 如果 State 对象没有实例变量（或者除了后继状态成员变量之外没有更多的实例变量了），那么各上下文可以共享同一个 State 对象，从而节省对象开销。

---

[下一篇](../Memento%20Pattern/README.md)