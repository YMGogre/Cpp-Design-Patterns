[上一篇](../Filter%20Pattern/README.md)

---

# 空对象模式 Null Object

## 1、动机

* 在许多情况下，对象的行为依赖于其状态。当对象的状态为 NULL 时，我们通常需要在代码中进行 NULL 检查，以防止出现空指针异常。然而，这种做法会使代码变得复杂，并且容易出错。
* 在这种时候，我们也许需要创建一个特殊的空对象，用来代替 NULL。这个空对象不做任何事情，但是它的行为（方法）与其他对象相同。这样，我们就可以像处理普通对象一样处理空对象，而不需要进行任何 NULL 检查。

> 在空对象模式中，一个空对象取代 NULL 对象实例的检查。`Null` 对象不是检查空值，而是反应一个不做任何动作的关系。这样的 `Null` 对象也可以在数据不可用的时候提供默认的行为。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>在需要检查空值的地方无缝地使用空对象类以防止出现空指针异常。</dd>
    <dt>关键代码</dt>
    <dd>实现一个空对象，具有实际对象期望的接口，但不执行任何操作。</dd>
</dl>

---

## 3、实现

### 步骤一

我们将创建一个定义操作（在这里，是客户的名字）的 AbstractCustomer 抽象类：

```cpp
class AbstractCustomer
{

protected:
	// 客户的名字
	std::string name;

public:
	AbstractCustomer(std::string _name) : name(_name) {}

	virtual bool isNil() = 0;
	virtual std::string getName() = 0;
	virtual ~AbstractCustomer() {}
};
```

> AbstractCustomer 允许我们可以操作客户的名字。比如其包含了一些纯虚的成员函数，其中：
> * `isNil()`：检查客户是否为空，这主要是通过检查客户的名字是否是空字符串来实现的；
> * `getName()`：用于获取客户的名字。

### 步骤二

接下来我们创建实现了 AbstractCustomer 类的实体类 RealCustomer 和 NullCustomer。其中 NullCustomer 即那个用来取代 NULL 对象的特殊的空对象：

```cpp
class RealCustomer :
	public AbstractCustomer
{

public:
	RealCustomer(std::string _name) : AbstractCustomer(_name) {}
	
	inline virtual std::string getName() override {
		return name;
	}
	
	inline virtual bool isNil() override {
		return false;
	}
};
```

```cpp
class NullCustomer :
	public AbstractCustomer
{

public:
	NullCustomer() : AbstractCustomer("") {}
	
	inline virtual std::string getName() override {
		return "Not Available in Customer Database";
	}
	
	inline virtual bool isNil() override {
		return true;
	}
};
```

> 可以看到，NullCustomer 不做任何事情，但其提供了默认的行为。所以我们可以像处理普通 RealCustomer 对象一样处理 NullCustomer 对象

### 步骤三

接下来我们创建一个客户工厂类 CustomerFactory：

```cpp
class CustomerFactory
{
public:
	static const std::string names[3];
	
	static inline AbstractCustomer* getCustomer(std::string name) {
		if (std::find(std::begin(names), std::end(names), name) != std::end(names)) {
			return new RealCustomer(name);
		}
		return new NullCustomer();
	}
};

// 定义静态成员
const std::string CustomerFactory::names[] = {"Rob", "Joe", "Julie"};
```

> CustomerFactory 包含一个静态成员常量：
> * `names`：用于存储所有的客户名字。
> 
> CustomerFactory 还包含一个静态成员函数：
> * `getCustomer(std::string name)`：获取客户对象。如果 `names` 中包含指定的客户名字，该函数将会返回 RealCustomer 对象指针；否则返回 NullCustomer 对象指针。

### 步骤四

在 `main()` 函数中，我们使用客户工厂 CustomerFactory，传递客户的名字，来获取 RealCustomer 或 NullCustomer 对象：

```cpp
int main() {
	AbstractCustomer* customer1 = CustomerFactory::getCustomer("Rob");
	AbstractCustomer* customer2 = CustomerFactory::getCustomer("Bob");
	AbstractCustomer* customer3 = CustomerFactory::getCustomer("Julie");
	AbstractCustomer* customer4 = CustomerFactory::getCustomer("Laura");

	std::cout << "Customers" << std::endl;
	std::cout << customer1->getName() << std::endl;
	std::cout << customer2->getName() << std::endl;
	std::cout << customer3->getName() << std::endl;
	std::cout << customer4->getName() << std::endl;
}
```

### 步骤五

执行程序，输出结果：

```plain
Customers
Rob
Not Available in Customer Database
Julie
Not Available in Customer Database
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 空对象模式提供了一种更加优雅、安全的方式来处理可能为 NULL 的对象。被广泛应用于各种需要处理可能为 NULL 的对象的场景。
* 在空对象模式中，空对象并不是用来检查空值的，而是反应一个不做任何动作的关系。空对象模式的主要目标是提供一个对象，它可以替代实际对象的空值，从而避免空指针异常。空对象通常会提供默认的行为。

---

[下一篇](../设计模式总结/设计模式总结.md)