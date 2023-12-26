[上一篇](../Observer%20Pattern/README.md)

---

# 💠 “单一职责”模式

在软件组件的设计中，如果责任划分得不清晰，使用继承得到的结果往往是随着需求的变化，子类急速膨胀，同时充斥着重复代码，这时候的关键是划清责任。

典型模式：
* 装饰模式 Decorator
* 桥接模式 Bridge

# 装饰（器）模式 Decorator

> 请注意，笔者在名称中使用了括号。这意味着在某些地方可能会将该模式称为“**装饰模式 Decorator**”。

## 1、动机

* 在某些情况下我们可能会“过度地使用继承来扩展对象的功能”，由于继承为类型引入的静态特质，使得这种扩展方式缺乏灵活性；并且随着子类的增多（扩展功能的增多），各种子类的组合（扩展功能的组合）会导致更多子类的膨胀。
* 如何使 “对象功能的扩展” 能够根据需要来动态地实现？同时避免 “扩展功能的增多” 带来的子类膨胀问题？从而使得任何 “功能扩展变化” 所导致的影响降到最低。

> 装饰（器）模式允许向一个现有的对象添加新的功能，同时又不改变其结构。这种类型的设计模式属于结构型模式，它是作为现有的类的一个包装。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>动态地给一个对象添加一些额外的职责。就增加功能来说，装饰器模式相比生成子类更为灵活。</dd>
    <dt>关键代码</dt>
    <dd><ol><li>抽象组件 Component 类充当抽象角色，不应该具体实现。</li><li>装饰器类引用和继承 Component 类，具体扩展类重写父类方法。</li></ol></dd>
</dl>

---

## 3、实现

### 步骤一

我们将创建一个抽象组件类 Shape，它将扮演抽象组件（Component）的角色，是定义了原始对象和装饰器对象的公共接口。

我们的 Shape 类如下：

```cpp
class Shape
{

public:
	virtual void render() = 0;
	virtual ~Shape() {}
};
```

### 步骤二

接下来我们创建实现了 Shape 类的实体类 Ellipse，它将重写抽象类的方法以渲染自身。在装饰模式中，Ellipse 类扮演了被装饰的原始对象的角色，它定义了需要添加新功能的对象：

```cpp
class Ellipse :
    public Shape
{

public:
    inline virtual void render() override {
        std::cout << "Shape: Ellipse" << std::endl;
    }
};
```

### 步骤三

接下来我们创建实现了 Shape 类的装饰器基类 ShapeDecorator，其拥有一个受保护的 Shape 类的引用成员变量 decoratedShape 引用了被装饰的 Shape 对象。同时 ShapeDecorator 通过构造函数的访问限制该类在外界被实例化。

我们的 ShapeDecorator 类如下：

```cpp
class ShapeDecorator :
	public Shape
{

protected:
	Shape& decoratedShape;
	inline ShapeDecorator(Shape& _decoratedShape) :
		decoratedShape(_decoratedShape) {
	}

public:
	inline virtual void render() override {
		decoratedShape.render();
	}
};
```

可以看到，装饰器基类引用和继承了抽象组件类 Shape。这意味着 ShapeDecorator 可以通过组合的方式持有其他装饰器对象。

> 💬 当然，在 ShapeDecorator 中，您也可以通过指针引用抽象组件类 Shape。比如 `Shape* decoratedShape;`

### 步骤四

接下来我们创建具体的装饰器类（Concrete Decorator）RedBorderShapeDecorator 和 GreenBackgroundShapeDecorator。它们继承自装饰器基类，负责向抽象组件添加新的功能。通常会在调用原始对象的方法之前或之后执行自己的操作：

```cpp
// 具体装饰器类添加了一个新的功能 —— 设置形状的红色边框
class RedBorderShapeDecorator :
	public ShapeDecorator
{

private:
	inline void setRedBorder(Shape& decoratedShape) {
		std::cout << "Border Color: Red" << std::endl;
	}

public:
	inline RedBorderShapeDecorator(Shape& _decoratedShape) :
		ShapeDecorator(_decoratedShape) {
	}
	inline virtual void render() override {
		decoratedShape.render();
		setRedBorder(decoratedShape);
	}
};

// 具体装饰器类添加了一个新的功能 —— 设置形状的绿色背景
class GreenBackgroundShapeDecorator :
	public ShapeDecorator
{

private:
	inline void setGreenBackground(Shape& decoratedShape) {
		std::cout << "Background Color: Green" << std::endl;
	}

public:
	inline GreenBackgroundShapeDecorator(Shape& _decoratedShape) :
		ShapeDecorator(_decoratedShape) {
	}
	inline virtual void render() override {
		decoratedShape.render();
		setGreenBackground(decoratedShape);
	}
};
```

### 步骤五

在 `main()` 函数中，我们使用具体的装饰器类（RedBorderShapeDecorator）对象来装饰具体的组件类（Ellipse）对象；并通过嵌套的方式使用具体的装饰器类（GreenBackgroundShapeDecorator）对象来装饰具体的装饰器类（RedBorderShapeDecorator）的对象：

```cpp
int main() {
	Ellipse ellipse;
	RedBorderShapeDecorator redEllipse(ellipse);
	// 装饰器可嵌套包装装饰器
	GreenBackgroundShapeDecorator redGreenEllipse(redEllipse);

	std::cout << "Ellipse with normal border" << std::endl;
	ellipse.render();

	std::cout << "\nEllipse of red border" << std::endl;
	redEllipse.render();

	std::cout << "\nEllipse of red border and green background" << std::endl;
	redGreenEllipse.render();
}
```

### 步骤六

执行程序，输出结果：

```plain
Ellipse with normal border
Shape: Ellipse

Ellipse of red border
Shape: Ellipse
Border Color: Red

Ellipse of red border and green background
Shape: Ellipse
Border Color: Red
Background Color: Green
```

### 步骤七

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 装饰类和被装饰类可以独立发展，不会相互耦合，装饰模式是继承的一个替代模式，装饰模式可以动态扩展一个实现类的功能。
* 装饰器模式通过嵌套包装多个装饰器对象，可以实现多层次的功能增强。每个具体装饰器类都可以选择性地增加新的功能，同时保持对象接口的一致性。
* 通过采用组合而非继承的手法，装饰（器）模式实现了在**运行时**动态扩展对象功能的能力，而且可以根据需要扩展多个功能。避免了使用继承带来的 “灵活性差” 和 “多子类衍生问题”。
* 装饰器类在接口上表现为 **is-a** 抽象组件的继承关系，即装饰器类继承了组件类所具有的接口。但又在实际表现为 **has-a** 抽象组件的组合关系，即装饰器类又使用了另外一个组件类。
* 装饰器模式的目的并非解决 “多子类衍生的多继承” 问题，装饰器模式应用的要点在于解决 “主体类在多个方向上的扩展功能” —— 是为 “装饰” 的含义。

---

[下一篇](../Bridge%20Pattern/README.md)