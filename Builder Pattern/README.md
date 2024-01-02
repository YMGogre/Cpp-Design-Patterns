[上一篇](../Prototype%20Pattern/README.md)

---

# 建造者模式 Builder

## 1、动机

* 在软件系统中，有时候面临着 “一个复杂对象” 的创建工作，其通常由各个部分的子对象用一定的算法构成；由于需求的变化，这个复杂对象的各个部分经常面临着剧烈的**变化**，但是将它们组合在一起的算法却相对**稳定**。
* 如何应对这种变化？如何提供一种 “封装机制” 来隔离出 “复杂对象的各个部分” 的变化，从而保持系统中的 “稳定构建算法” 不随着需求改变而改变？

> 建造者模式使用多个简单的对象一步一步构建成一个复杂的对象。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>将一个复杂的构建与其表示相分离，使得同样的构建过程可以创建不同的表示。</dd>
    <dt>关键代码</dt>
    <dd>建造者：创建和提供实例，导演：管理建造出来的实例的依赖关系。</dd>
</dl>

---

## 3、实现

我们想在假设一个快餐店的商业案例。其中，一个典型的套餐可以是一个汉堡（Burger）和一杯冷饮（Cold drink）。汉堡（Burger）可以是素食汉堡（Veg Burger）或鸡肉汉堡（Chicken Burger），它们是包在纸盒中。冷饮（Cold drink）可以是可口可乐（coke）或百事可乐（pepsi），它们是装在瓶子中。

我们将创建一个表示食物条目（比如汉堡和冷饮）的 Item 接口和实现 Item 接口的实体类，以及一个表示食物包装的 Packing 接口和实现 Packing 接口的实体类，汉堡是包在纸盒中，冷饮是装在瓶子中。

然后我们创建一个 Meal 套餐类，其带有 Item 的动态数组；再创建一个通过结合 Item 来生成不同类型的 Meal 对象的 MealBuilder。最终在 `main()` 函数中我们使用 MealBuilder 来创建一个 Meal。

### 步骤一

首先我们创建表示食物条目和食物包装的接口 Item 和 Packing。

我们的 Item 和 Packing 类如下：

```cpp
class Item {

public:
	virtual std::string name() = 0;
	virtual Packing* packing() = 0;
	virtual float price() = 0;
	virtual ~Item() {}
};
```

> Item 类包含一些纯虚成员函数，比如 `name()` 用于返回食物的名称；`packing()` 用于返回食物的包装；`price()` 用于返回食物的价格。

```cpp
class Packing {

public:
	virtual std::string pack() = 0;
	virtual ~Packing() {}
};
```

> Packing 类包含一些纯虚成员函数，比如 `pack()` 用于返回包装的名称。

### 步骤二

接下来我们创建实现了 Packing 接口的实体包装类 Wrapper（纸盒）以及 Bottle（瓶子）：

```cpp
class Wrapper :
    public Packing
{

public:
    inline virtual std::string pack() override {
        return "Wrapper";
    }
};

class Bottle :
	public Packing
{

public:
	inline virtual std::string pack() override {
		return "Bottle";
	}
};
```

### 步骤三

接下来我们创建部分实现了 Item 接口的抽象类 Burger 和 ColdDrink。它们只实现了 Item 的 `packing()` 函数返回各自包装对象的指针。

我们的 Burger 和 ColdDrink 类如下：

```cpp
class Burger :
	public Item
{

public:
	inline virtual Packing* packing() override {
		return new Wrapper();
	}
};

class ColdDrink :
	public Item
{

public:
	inline virtual Packing* packing() override {
		return new Bottle();
	}
};
```

### 步骤四

随后我们创建实现了 Burger 抽象类的实体类 VegBurger 和 ChickenBurger；以及实现了 ColdDrink 抽象类的实体类 Coke 和 Pepsi。

它们分别如下：

```cpp
class VegBurger :
	public Burger
{

public:
	inline virtual std::string name() override {
		return "Veg Burger";
	}
	inline virtual float price() override {
		return 25.0f;
	}
};

class ChickenBurger :
	public Burger
{

public:
	inline virtual std::string name() override {
		return "Chicken Burger";
	}
	inline virtual float price() override {
		return 50.5f;
	}
};
```

```cpp
class Coke :
	public ColdDrink
{

public:
	inline virtual std::string name() override {
		return "Coke";
	}
	inline virtual float price() override {
		return 30.0f;
	}
};

class Pepsi :
	public ColdDrink
{

public:
	inline virtual std::string name() override {
		return "Pepsi";
	}
	inline virtual float price() override {
		return 35.0f;
	}
};
```

> 到目前为止所有的类都很简单；接下来我们将尝试使用这些简单的对象去构建一个复杂的对象。

### 步骤五

我们创建一个 Meal 套餐类，带有上面定义的 Item 对象：

```cpp
class Meal {

private:
	std::vector<Item*> items;

public:
	inline void addItem(Item* const& item) {
		items.push_back(item);
	}
	inline float getCost() {
		float cost = 0.0f;
		for (auto item : items) {
			cost += item->price();
		}
		return cost;
	}
	inline void showItems() {
		for (auto item : items) {
			std::cout << "Item: " << item->name()
			<< ", Packing: " << item->packing()->pack()
			<< ", Price: " << item->price() << std::endl;
		}
	}

	~Meal() {
		for (auto item : items) {
			delete item;
		}
	}
};
```

> Meal 类使用一个 Item 指针类型的动态数组存储套餐中包含的食物条目。此外 Meal 类还包含一些成员函数：
> * `addItem(Item* const& item)` 函数允许向套餐添加食物条目；
> * `getCost()` 用于获取套餐的价格；
> * `showItems()` 用于展示套餐内包含的食物。

### 步骤六

最后我们创建一个 MealBuilder 套餐建造者类，其负责创建 Meal 对象。

我们的 MealBuilder 类如下：

```cpp
class MealBuilder
{

public:
	inline Meal prepareVegMeal() {
		Meal meal;
		meal.addItem(new VegBurger());
		meal.addItem(new Coke());
		return meal;
	}
	inline Meal prepareNonVegMeal() {
		Meal meal;
		meal.addItem(new ChickenBurger());
		meal.addItem(new Pepsi());
		return meal;
	}
};
```

> * `prepareVegMeal()` 用于创建并返回素食套餐对象；
> * `prepareNonVegMeal()` 用于创建并返回非素食套餐对象。
> * 所谓 “**将一个复杂的构建与其表示相分离，使得同样的构建过程可以创建不同的表示**”，在本示例中体现在：
> 
> 	1. Meal 只负责对象的表示，它只表现一个套餐对象的属性和行为；而 MealBuilder 将负责对象的构建，以此完成将一个复杂的构建与其表示相分离。
> 	2. `prepareVegMeal()` 和 `prepareNonVegMeal()` 使用了相同的步骤来构建 Meal 对象（即添加 Item），但是它们创建的 Meal 对象的表示却不同。

### 步骤七

在 `main()` 函数中，我们使用 MealBuilder 来创建一个套餐：

```cpp
int main() {
	MealBuilder mealBuilder;

	auto vegMeal = mealBuilder.prepareVegMeal();
	std::cout << "Veg Meal" << std::endl;
	vegMeal.showItems();
	std::cout << "Total Cost: " << vegMeal.getCost() << std::endl;

	auto nonVegMeal = mealBuilder.prepareNonVegMeal();
	std::cout << "\n\nNon-Veg Meal" << std::endl;
	nonVegMeal.showItems();
	std::cout << "Total Cost: " << nonVegMeal.getCost() << std::endl;
}
```

### 步骤八

执行程序，输出结果：

```plain
Veg Meal
Item: Veg Burger, Packing: Wrapper, Price: 25
Item: Coke, Packing: Bottle, Price: 30
Total Cost: 55


Non-Veg Meal
Item: Chicken Burger, Packing: Wrapper, Price: 50.5
Item: Pepsi, Packing: Bottle, Price: 35
Total Cost: 85.5
```

### 步骤九

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 建造者模式主要用于 “分步骤构建一个复杂的对象”。在这其中 “分步骤” 是一个**稳定**的算法（对于本示例代码 “分步骤” 即 `prepareVegMeal()` 和 `prepareNonVegMeal()` 函数中的那些步骤：首先创建一个空的 Meal 对象；然后调用 Meal 对象的 `addItem()` 方法添加 Item，这个操作可能会被执行多次；最后返回构建好的 Meal 对象。这两个方法都遵循了这个稳定的步骤），而复杂对象的各个部分则经常**变化**（对于不同的套餐，有不同的 Item）。
* 在实际工程中，使用建造者模式的时候可能并不多。
* 变化点在哪里，就封装哪里 —— 建造者模式主要在于应对 “复杂对象各个部分” 的频繁需求变动。其缺点在于难以应对 “分步骤构建算法” 的需求变动。
* 在建造者模式中，要注意不同语言中构造函数内调用虚函数的差别（C++ or C#）。我们知道 C++ 不能在构造函数中使用虚函数的动态绑定（[了解更多...](https://www.zhihu.com/question/418284595)）。

---

[下一篇](../Singleton%20Pattern/README.md)