[上一篇](../Chain%20of%20Responsibility%20Pattern/README.md)

---

# 💠 “行为变化”模式

在组件的构建过程中，组件行为的变化经常导致组件本身剧烈的变化。“行为变化” 模式将组件的行为和组件本身进行解耦，从而支持组件行为的变化，实现两者之间的松耦合。

> 这里所说的组件的 “**行为**”，通常就是指一段代码，比如说一个成员函数，它可以完成某种操作（比如说打印输出），那么这个成员函数就代表了组件的一种行为（打印输出）。

典型模式：
* 命令模式 Command
* 访问者模式 Visitor

# 命令模式 Command

## 1、动机

* 在软件构建过程中，“行为请求者” 与 “行为实现者” 通常呈现一种 “紧耦合”。但在某些场合 —— 比如需要对行为进行 “记录、撤销 / 重做、事务” 等处理，这种无法抵御变化的紧耦合是不合适的。
* 在这种情况下，如何将 “行为请求者” 与 “行为实现者” 解耦？将一组行为抽象为对象，可以实现二者之间的松耦合。

> 命令模式是一种数据驱动的设计模式，它属于行为型模式。**请求以命令的形式包裹在对象中**，并传给调用对象。调用对象寻找可以处理该命令的合适的对象，并把该命令传给相应的对象，该对象执行命令。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>将一个请求封装成一个对象，从而使您可以用不同的请求对客户进行参数化。</dd>
    <dt>关键代码</dt>
    <dd>定义三个角色：1、received 真正的命令执行对象 2、Command 3、invoker 使用命令对象的入口</dd>
</dl>

---

## 3、实现

### 步骤一

首先我们将创建一个抽象命令类 Order：

```cpp
class Order
{

public:
	virtual void execute() = 0;
	virtual ~Order() {}
};
```

> Order 包含一个纯虚成员函数：
> * `execute()`：用于执行命令的接口。
>
> 以此我们得以将一组行为抽象为对象，Order 的子类对象只包含一个 `execute()` 函数，表征一个行为。

### 步骤二

接下来我们创建作为真正的命令执行对象的 Stock 股票类。在命令模式中其扮演 “***行为实现者***” 的角色，它知道如何执行与请求相关的操作：

```cpp
class Stock
{

private:
	// 名称
	const char* name = "ABC";
	// 数量
	int quantity = 10;

public:
	inline void buy() {
		std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] bought" << std::endl;
	}

	inline void sell() {
		std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] sold" << std::endl;
	}
};
```

> Stock 包含一些成员函数，其中：
> * `buy()`：实现购买股票行为；
> * `sell()`：实现出售股票行为。

### 步骤三

接下来我们创建实现了 Order 类的实体命令类 BuyStock 和 SellStock。它们将使用 Stock 分别执行实际的购买股票和出售股票命令处理：

```cpp
class BuyStock :
	public Order
{

private:
	Stock abcStock;

public:
	BuyStock(Stock _abcStock) : abcStock(_abcStock) {}
	inline virtual void execute() {
		abcStock.buy();
	}
};

class SellStock :
	public Order
{

private:
	Stock abcStock;

public:
	SellStock(Stock _abcStock) : abcStock(_abcStock) {}
	inline virtual void execute() {
		abcStock.sell();
	}
};
```

> 实体命令类会执行相应的操作。具体来说：
> * 在 BuyStock 类中，`execute()` 方法会调用 Stock 类的 `buy()` 方法来购买股票；
> * 在 SellStock 类中，`execute()` 方法会调用 Stock 类的 `sell()` 方法来卖出股票。
>
> **Q：为什么不是具体的命令类去实现行为呢？**
> > A：在命令模式中，具体命令对象（如 BuyStock 和 SellStock）确实负责执行特定的行为，但这些行为通常是通过调用接收者（在这个例子中是 Stock 类）的方法来实现的。
> >
> > 这样做的原因是，命令对象的目的是将一个操作封装为一个对象，这个操作可能涉及到多个接收者对象或者需要在多个接收者对象之间协调行为。如果将所有的实现逻辑都放在命令对象中，那么命令对象可能会变得过于复杂，而且可能会违反单一职责原则，即一个类应该只有一个引起它变化的原因。
> >
> > 另外，将实现逻辑放在接收者中可以提高代码的复用性。例如，如果有多个命令需要执行相同的操作（如购买股票），那么这个操作只需要在接收者中实现一次，然后由需要的命令去调用即可。
> >
> > 总的来说，虽然具体命令对象负责执行特定的行为，但这些行为的具体实现通常是由接收者完成的。这样可以使命令对象保持简单，同时提高代码的复用性。

### 步骤四

接下来我们创建命令的调用者 Broker，在命令模式中其扮演 “***行为请求者***” 的角色。
* 其通过 `takeOrder(Order* order)` 方法接受命令；
* 并通过 `placeOrders()` 方法请求命令的执行：

```cpp
class Broker
{

private:
	std::vector<Order*> orderList;

public:
	// 接受命令，该方法将新的命令加入到命令列表
	inline void takeOrder(Order* order) {
		orderList.push_back(order);
	}

	// 该方法将会执行命令列表中的所有命令
	inline void placeOrders() {
		for (Order* order : orderList) {
			order->execute();
		}
		orderList.clear();
	}
};
```

> 在 `placeOrders()` 方法中，Broker 可以通过调用命令对象的 `execute()` 方法来发出请求，而不需要知道这些请求是如何被实现的。以此，我们得以将 “行为请求者” 和 “行为实现者” 解耦。

### 步骤五

在 `main()` 函数中，我们使用 Broker 来接受并执行命令：

```cpp
int main() {
	Stock abcStock;

	BuyStock buyStock(abcStock);
	SellStock sellStock(abcStock);

	Broker broker;
	broker.takeOrder(&buyStock);
	broker.takeOrder(&sellStock);

	broker.placeOrders();
}
```

### 步骤六

执行程序，输出结果：

```plain
Stock [ Name: ABC, Quantity: 10 ] bought
Stock [ Name: ABC, Quantity: 10 ] sold
```

### 步骤七

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 命令模式的根本目的在于将 “行为的请求者” 与 “行为的实现者” 解耦，在面向对象语言中，常见的实现手段是 “将行为抽象为对象”。
* 实现命令接口的具体命令对象有时候根据需要可能会保存一些额外的状态信息。通过使用[组合模式](../Composite%20Pattern/README.md)，可以将多个 “命令” 封装为一个 “复合命令”。
* 命令模式与 C++ 中的[函数对象](https://zhuanlan.zhihu.com/p/87387720)有些类似。但两者定义行为接口的规范有所区别：命令模式以面向对象中的 “接口-实现” 来定义行为接口规范，更严格，但有性能损失；C++ 函数对象以函数签名来定义行为接口规范，更灵活，性能更高。

---

[下一篇](../Visitor%20Pattern/README.md)