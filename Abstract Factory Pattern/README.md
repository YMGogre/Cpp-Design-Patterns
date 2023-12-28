[上一篇](../Factory%20Pattern/README.md)

---

# 抽象工厂模式 Abstract Factory

## 1、动机

* 在软件系统中，经常面临着 “**一系列相互依赖的对象**” 的创建工作；同时，由于需求的变化，往往存在更多系列对象的创建工作。
* 如何应对这种变化？如何绕过常规的对象创建方法（`new`），提供一种 “封装机制” 来避免客户程序和这种 “多系列具体对象创建工作” 的紧耦合？

> 什么是「一系列相互依赖的对象」呢？
> * 比如一整套西装，那么西服、西裤、皮鞋、领带这一系列的对象都是相互依赖的；它们共同组成了一套西装。它们的依赖性体现在你最好不要尝试使用一件西服去搭配一条牛仔短裤，那样会看起来很奇怪。
> * 又比如我们想要访问数据库，无论是 SQL Server、Oracle、MySQL、PostgreSQL 或 DB2 等等，通常都需要如下一些基本组件：连接对象（Connection）、SQL 命令对象（Command）、数据读取器对象（DataReader）等等。这一系列的对象都是相互依赖的，它们共同组成了访问一个数据库的基本要素。它们的依赖性体现在你不能使用 SQL Server 的连接对象（Connection）去搭配 Oracle 的 SQL 命令对象（Command）或者 MySQL 的数据读取器对象（DataReader），它们都不是一组的。
>
> 所以，我们需要一个工厂，要创建就创建一套这样相互依赖的对象出来。比如说一整套西装对象，或者一整套的访问 SQL Server 数据库的基本组件对象。这样的工厂即 **抽象工厂**。
> 
> 抽象工厂模式是围绕一个超级工厂创建其他工厂。该超级工厂又称为其他工厂的工厂。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。在抽象工厂模式中，接口是负责创建一个相关对象的工厂，不需要显式指定它们的类。每个生成的工厂都能按照工厂模式提供对象。
> > 什么意思呢？其实这段话都是在形容这一句代码：
> > ```cpp
> > // 抽象工厂(接口)* 具体工厂对象 = new 负责创建一系列相关或相互依赖对象的具体工厂类();
> > AbstractFactory* abstractFactory = new ConcreteFactory();
> > ```
> > 所谓「超级工厂又称为其他工厂的工厂」，并不是指抽象工厂提供了创建具体工厂的成员函数；毕竟抽象工厂只声明了一组用于创建产品对象的方法，每个方法对应一种产品类型，而所有的具体工厂类都实现了这个抽象工厂接口。但每当我们想要创建一个具体工厂对象时，我们会将其类型声明为抽象工厂的指针（或引用）。所以我们可以理解为我们使用了一个抽象工厂的指针（或引用）创建了一个具体工厂的对象，不需要显式指定具体工厂的类型。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。</dd>
    <dt>关键代码</dt>
    <dd>在一个工厂里聚合多个同类（同主题）产品。</dd>
</dl>

## 3、实现

### 步骤一

为形状创建一个接口 Shape，在抽象工厂模式中，Shape 扮演抽象产品的角色。其定义了产品的共同接口，规定了产品对象的共同方法。

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

接下来我们为颜色创建一个接口 Color，在抽象工厂模式中，Shape 类扮演抽象产品的角色。其定义了产品的共同接口，规定了产品对象的共同方法。

我们的 Color 类如下：

```cpp
class Color {

public:
	virtual void fill() = 0;
	virtual ~Color() {};
};
```

### 步骤四

接下来我们创建实现 Color 类的具体产品类 Green 和 Blue；它们包含具体产品的特定行为或属性。

比如 Green 的 `fill()` 函数将会填充绿色；而 Blue 的 `fill()` 函数将会填充蓝色：

```cpp
class Green :
    public Color
{

public:
    inline virtual void fill() override {
        std::cout << "Inside Green::fill() method." << std::endl;
    }
};

class Blue :
    public Color
{

public:
    inline virtual void fill() override {
        std::cout << "Inside Blue::fill() method." << std::endl;
    }
};
```

### 步骤五

接下来我们创建抽象工厂类 AbstractFactory，其声明了一组用于创建产品对象的方法，每个方法对应一种产品类型。

我们的 AbstractFactory 类如下：

```cpp
class AbstractFactory {

public:
	virtual Shape* getShape(const char* shape) = 0;
	virtual Color* getColor(const char* color) = 0;
	virtual ~AbstractFactory() {};
};
```

> 在 AbstractFactory 类中：
> * `getShape(const char* shape)` 用于创建「形状」产品对象；
> * `getColor(const char* color)` 用于创建「颜色」产品对象。

### 步骤六

接下来我们创建实现 AbstractFactory 的具体工厂类 ShapeFactory 和 ColorFactory，他们将分别负责创建「形状」产品和「颜色」产品的对象：

```cpp
class ShapeFactory :
    public AbstractFactory
{

public:
    inline virtual Shape* getShape(const char* shapeType) override {
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
    inline virtual Color* getColor(const char* colorType) override {
        return nullptr;
    }
};

class ColorFactory :
    public AbstractFactory
{

public:
    inline virtual Shape* getShape(const char* shapeType) override {
        return nullptr;
    }
    inline virtual Color* getColor(const char* colorType) override {
        if (colorType == nullptr) {
            return nullptr;
        }
        if (strcmp(colorType, "Green") == 0) {
            return new Green();
        }
        else if (strcmp(colorType, "Blue") == 0) {
            return new Blue();
        }
        return nullptr;
    }
};
```

> <p align="center">⚠️</p>
> 请注意，这一步的 ShapeFactory 和 ColorFactory 其实并不是用于创建一系列相关或相互依赖对象的具体工厂类。ShapeFactory 还是只负责创建「形状」产品对象；ColorFactory 还是只负责创建「颜色」产品对象。
>
> 这主要是出于「形状」和「颜色」本就没有太大的相关或者说相互依赖性的考虑。但如果你喜欢的话，你可以创造一些「主题」出来，使它们成为有相互依赖的对象。比如：
>
> ```cpp
> class GreenRectangleFactory :
> 	  public AbstractFactory
> {
>
> public:
> 	  inline virtual Shape* getShape(const char* shapeType) override {
> 		  return new Rectangle();
> 	  }
> 	  inline virtual Color* getColor(const char* colorType) override {
> 	  	  return new Green();
> 	  }
> };
> ```
>
> GreenRectangleFactory 负责创建一组具有相同主题的产品，这里的「主题」就是「绿色矩形」。而对于本文开头提到的例子，「主题」就可以是 “西装” 或者 “休闲装” 以及 “适用于 SQL Server 的数据库访问组件” 或者 “适用于 Oracle 的数据库访问组件”。
> 
> 不过无论如何，我们现有的示例代码就已经完成了抽象工厂模式所有核心代码：即便目前我们的具体工厂类并没有真正负责创建一系列相关或相互依赖的对象；但我们的抽象工厂类还是提供了创建一系列相关或相互依赖对象的接口的。

### 步骤七

接下来我们创建一个工厂创造器/生成器类 FactoryProducer，通过传递形状或者颜色信息来获取对应的具体工厂：

```cpp
class FactoryProducer
{

public:
	static inline AbstractFactory* getFactory(const char* choice) {
		if (strcmp(choice, "SHAPE") == 0) {
			return new ShapeFactory();
		}
		else if (strcmp(choice, "COLOR") == 0) {
			return new ColorFactory();
		}
		return nullptr;
	}
};
```

### 步骤八

在 `main()` 函数中，我们通过工厂创造器（FactoryProducer）来获取具体工厂的对象。随后我们使用这些工厂，通过传递类型信息来获取实体类的对象：

```cpp
int main() {
	// 获取形状工厂
	AbstractFactory* shapeFactory = FactoryProducer::getFactory("SHAPE");

	// 获取形状为 Rectangle 的对象
	Shape* shape1 = shapeFactory->getShape("Rectangle");

	// 调用 Rectangle 的 render() 方法
	shape1->render();

	// 获取形状为 Ellipse 的对象
	Shape* shape2 = shapeFactory->getShape("Ellipse");

	// 调用 Ellipse 的 render() 方法
	shape2->render();

	// 获取颜色工厂
	AbstractFactory* colorFactory = FactoryProducer::getFactory("COLOR");

	// 获取颜色为 Green 的对象
	Color* color1 = colorFactory->getColor("Green");

	// 调用 Green 的 fill() 方法
	color1->fill();

	// 获取颜色为 Blue 的对象
	Color* color2 = colorFactory->getColor("Blue");

	// 调用 Blue 的 fill() 方法
	color2->fill();
}
```

### 步骤九

执行程序，输出结果：

```plain
Inside Rectangle::render() method.
Inside Ellipse::render() method.
Inside Green::fill() method.
Inside Blue::fill() method.
```

### 步骤十

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 如果没有应对 “多系列对象构建” 的需求变化，则没有必要使用抽象工厂模式，这时候使用简单的工厂完全可以。
* “系列对象” 指的是在某一特定系列下的对象之间有相互依赖或作用的关系。不同系列的对象之间不能相互依赖。
* 抽象工厂模式主要在于应对 “新系列” 的需求变动。其缺点在于难以应对 “新对象” 的需求变动。

---

[下一篇](../Prototype%20Pattern/README.md)