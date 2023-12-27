[上一篇](../Bridge%20Pattern/README.md)

---

# 💠 “对象创建”模式

通过 “对象创建” 绕开 `new`，来避免对象创建（`new`）过程中所导致的紧耦合（依赖具体类），从而支持对象创建的稳定。它是接口抽象之后的第一步工作。

典型模式：
* 工厂模式 Factory
* 抽象工厂模式 Abstract Factory
* 原型模式 Prototype
* 建造者模式 Builder

---

# 工厂模式 Factory

> 工厂模式是一个广泛的概念，包括
> * **简单工厂模式 Simple Factory**
> * **工厂方法模式 Factory Method**
> * **抽象工厂模式 Abstract Factory**
> 
> 本文主要介绍前两种模式，**抽象工厂模式 Abstract Factory** 将在下一篇介绍。

## 1、动机

* 在软件系统中，经常面临着创建对象的工作；由于需求的变化，需要创建的对象的具体类型经常变化。
* 如何应对这种变化？如何绕过常规的对象创建方法（`new`），提供一种 “封装机制” 来避免客户程序和这种 “具体对象创建工作” 的紧耦合？

> 工厂模式是最常用的设计模式之一。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。

---

# 📌 简单工厂模式 Simple Factory

## 1、介绍

<dl>
    <dt>意图</dt>
    <dd>定义一个工厂类，专门负责创建一些类（产品）的实例。</dd>
    <dt>关键代码</dt>
    <dd>对象的创建逻辑将隐藏于工厂类中</dd>
</dl>

---

## 2、实现

### 步骤一

我们将创建一个抽象产品类 Shape，其定义了产品的共同接口，规定了产品对象的共同方法。

我们的 Shape 类如下：

```cpp
class Shape {

public:
	virtual void render() = 0;
	virtual ~Shape() {};
};
```

### 步骤二

接下来我们创建实现 Shape 类的具体产品类 Rectangle 和 Ellipse；它们包含具体产品的特定行为或属性。

比如 Rectangle 的 `render()` 函数将会渲染一个矩形；而 Ellipse 的 `render()` 函数将会渲染一个椭圆：

```cpp
class Rectangle :
    public Shape
{

public:
    inline virtual void render() override {
        std::cout << "Inside Rectangle::render() method." << std::endl;
    }
};

class Ellipse :
    public Shape
{

public:
    inline virtual void render() override {
        std::cout << "Inside Ellipse::render() method." << std::endl;
    }
};
```

### 步骤三

接下来我们创建一个工厂类，负责创建具体产品的对象：

```cpp
class ShapeFactory
{

public:
	inline Shape* getShape(const char* shapeType) {
	    if (shapeType == nullptr) {
		    return nullptr;
	    }
	    if (strcmp(shapeType, "Rectangle") == 0) {
		    return new Rectangle();
	    }
	    else if (strcmp(shapeType, "Ellipse") == 0) {
		    return new Ellipse();
	    }
	    return nullptr;
    }
};
```

### 步骤四

在 `main()` 函数中，我们使用工厂，通过传递类型信息来获取实体类的对象并调用其 `render()` 方法：

```cpp
int main() {
	ShapeFactory *shapeFactory = new ShapeFactory();

	Shape* shape1 = shapeFactory->getShape("Rectangle");
	shape1->render();

	Shape* shape2 = shapeFactory->getShape("Ellipse");
	shape2->render();

	delete shapeFactory;
	delete shape1;
	delete shape2;
}
```

### 步骤五

执行程序，输出结果：

```plain
Inside Rectangle::render() method.
Inside Ellipse::render() method.
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

# 📌 工厂方法模式 Factory Method

上面介绍的简单工厂模式仍然存在一些缺陷，比如：每当我们新增加一个产品类（比如 `class Triangle`）时，我们就需要去修改 [`ShapeFactory`](#步骤三) 成员函数 `getShape(const char* shapeType)` 中的 `if-else` 语句，比如：

```cpp
else if (strcmp(shapeType, "Triangle") == 0) {
    return new Triangle();
}
```

这看起来像只是新增了一个 `else if` 分支，并没有修改已有代码。但这仍然视为对工厂类的修改，因为我们改变了它的行为。显然这违背了 **开闭原则**。

于是，工厂方法模式出现了。

## 1、介绍

<dl>
    <dt>意图</dt>
    <dd>定义一个创建对象的接口，让其子类自己决定实例化哪一个类，工厂模式使得一个类创建过程延迟到子类进行。</dd>
    <dt>关键代码</dt>
    <dd>创建过程在其子类执行。</dd>
</dl>

## 2、实现

### 步骤一

同简单工厂模式[步骤一](#步骤一)

### 步骤二

同简单工厂模式[步骤二](#步骤二)

### 步骤三

不同于简单工厂模式步骤三，我们创建的 ShapeFactory 类将成为一个抽象工厂类：

```cpp
class ShapeFactory {

public:
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() {};
};
```

### 步骤四

接下来我们创建实现了 ShapeFactory 的具体工厂类 RectangleFactory 和 EllipseFactory，它们将分别负责创建 Rectangle 和 Ellipse 的实例：

```cpp
class RectangleFactory : public ShapeFactory {

public:
    inline virtual Shape* createShape() override {
        return new Rectangle();
    }
};

class EllipseFactory : public ShapeFactory {

public:
    inline virtual Shape* createShape() override {
        return new Ellipse();
    }
};
```

> 创建对象的接口（ShapeFactory）的子类将自己决定实例化哪一个（产品）类。具体来说，RectangleFactory 负责实例化 Rectangle；EllipseFactory 负责实例化 Ellipse。
> 
> 可见，在工厂方法模式中，具体工厂类是与具体产品类一一对应的。每当我们新增一个产品类，直接增加新的工厂类就可以了，这符合 **开闭原则**。

### 步骤五

在 `main()` 函数中，我们使用不同的具体工厂对象来获取不同实体类的对象并调用其 `render()` 方法：

```cpp
int main() {
    ShapeFactory *rectangleFactory = new RectangleFactory();
    Shape* shape1 = rectangleFactory->createShape();
    shape1->render();

    ShapeFactory *ellipseFactory = new EllipseFactory();
    Shape* shape2 = ellipseFactory->createShape();
    shape2->render();

    delete rectangleFactory;
    delete ellipseFactory;
    delete shape1;
    delete shape2;
}
```

> 看到这里，笔者也不禁疑惑：“这不是多此一举吗？我要创建不同的形状，还得先创建不同的具体工厂对象。我直接 `Shape* shape1 = new Rectangle();` 不好吗？”
>
> 这里就要提出工厂模式的一个关键点了：在上面的例子中，我们其实创建的是一些很简单的对象。但是，**如果我们要创建一个复杂对象呢**？
> 
> 比如要创建的对象需要一系列复杂的初始化操作，如查配置文件、查数据库表、初始化成员对象等；而我们可能只是想使用这个对象而不关心它究竟是如何被创建的。
> 
> 此时我们就可以定义一个类来专门负责对象的创建，这样的类就是 **工厂类**。工厂模式可以将对象的创建过程封装起来，使得客户端代码不需要知道对象是如何创建的。这样，如果对象的创建过程很复杂，或者需要一些初始化操作，你可以将这些逻辑隐藏在工厂类中，使得客户端代码更简洁、更易于理解。

### 步骤六

执行程序，输出结果：

```plain
Inside Rectangle::render() method.
Inside Ellipse::render() method.
```

### 步骤七

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

# 总结

* 工厂模式用于隔离类对象的使用者和具体的类型之间的耦合关系。面对一个经常变化的具体类型，紧耦合关系（`new`）会导致软件的脆弱。
* 工厂方法模式通过面向对象的手法，将所有要创建的具体对象工作延迟到子类，从而实现一种扩展（而非更改）的策略，较好地解决了这种紧耦合关系。
* 工厂方法模式解决 “单个对象” 的需求变化。缺点在于要求创建方法 / 参数相同

---

[下一篇](../Abstract%20Factory%20Pattern/README.md)