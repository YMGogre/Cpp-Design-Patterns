[上一篇](../Abstract%20Factory%20Pattern/README.md)

---

# 原型模式 Prototype

## 1、动机

在软件系统中，经常面临着 “某些结构复杂的对象” 的创建工作；由于需求的变化，这些对象经常面临着剧烈的**变化**，但是它们却拥有比较**稳定**一致的接口。

如何应对这种变化？如何向 “客户程序（使用这些对象的程序）” 隔离出 “这些易变对象”，从而使得 “依赖这些易变对象的客户程序” 不随着需求改变而改变？

> 原型模式是用于创建重复的对象，同时又能保证性能。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式之一。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。</dd>
    <dt>关键代码</dt>
    <dd>通过拷贝构造函数返回自身的副本。</dd>
</dl>

---

## 3、实现

> 由于语言设计和内存管理的不同，不同的 OOP 语言对原型模式的实现方式有些微差别。比如：
>
> * 在 Java 中，所有的对象都是通过引用来访问的，所以当你尝试复制一个对象时，你实际上只是复制了对象的引用，而不是对象本身。为了实现对象的复制，Java 提供了 `Cloneable` 接口和 `clone()` 方法。所以 Java 的原型模式实现需要我们去实现 `Cloneable` 接口并重写 `clone()` 方法。
> * C# 也是类似，在 .NET 中，`Object` 类提供了 `MemberwiseClone()` 方法来实现对象的浅拷贝，这是通过复制对象的所有字段来实现的。对于深拷贝，.NET 提供了通过序列化的方式来实现，这需要将对象序列化为一个流，然后再从流中反序列化为一个新的对象。
> * 相比之下，C++ 提供了更直接和灵活的方式来实现对象的复制。在 C++ 中，我们可以通过拷贝构造函数或者赋值运算符来复制一个对象。这种方式不需要实现任何接口或方法。

### 步骤一

我们将创建一个抽象类 Shape，其将声明一个 `clone()` 纯虚成员函数用于克隆对象（自己），该函数返回 Shape 类的智能指针：

```cpp
class Shape
{

public:
	virtual std::unique_ptr<Shape> clone() const = 0;
	virtual void render() const = 0;
	virtual std::string getType() const = 0;
	virtual ~Shape() {}
};
```

### 步骤二

接下来我们创建实现了 Shape 的实体原型类 Rectangle 和 Ellipse。它们将实现基类的 `clone()` 函数：

```cpp
class Rectangle :
	public Shape
{

private:
	std::string type;

public:
	Rectangle() : type("Rectangle") {}
	inline virtual std::unique_ptr<Shape> clone() const override {
		// 通过拷贝构造，我们创建了一个新的原型类的实例，并返回一个指向它的指针（发生一次深拷贝）
		return std::make_unique<Rectangle>(*this);
	}
	inline virtual void render() const override {
		std::cout << "Inside Rectangle::render() method." << std::endl;
	}
	inline virtual std::string getType() const override {
		return type;
	}
};

class Ellipse :
	public Shape
{

private:
	std::string type;

public:
	Ellipse() : type("Ellipse") {}
	inline virtual std::unique_ptr<Shape> clone() const override {
		// 通过拷贝构造，我们创建了一个新的原型类的实例，并返回一个指向它的指针（发生一次深拷贝）
		return std::make_unique<Ellipse>(*this);
	}
	inline virtual void render() const override {
		std::cout << "Inside Ellipse::render() method." << std::endl;
	}
	inline virtual std::string getType() const override {
		return type;
	}
};
```

> 请注意在拷贝构造时我们需要进行深拷贝，因为原型实例应当只用于克隆；而不应当直接拿来使用。我们知道浅拷贝不会复制指针成员变量所指向的内存，这会导致原型实例的状态被修改。
>
> 当然，由于我们的 Rectangle 和 Ellipse 类不包含指针成员变量，所以浅拷贝和深拷贝的效果是一致的。如果实体原型类包含指针成员变量，那么我们需要自己写拷贝构造函数以满足深拷贝的要求。

### 步骤三

接下来我们创建原型管理器类 ShapeCache。其使用一张哈希表存储实体原型类对象，并提供成员函数以在请求的时候返回这些对象的克隆。

我们的 ShapeCache 类如下：

```cpp
class ShapeCache
{

private:
	std::unordered_map<std::string, std::unique_ptr<Shape>> shapeMap;

public:
	inline ShapeCache() {
		shapeMap["Rectangle"] = std::make_unique<Rectangle>();
		shapeMap["Ellipse"] = std::make_unique<Ellipse>();
	}
	inline std::unique_ptr<Shape> getShape(const std::string& type) {
		return shapeMap[type]->clone();
	}
};
```

> 通过传递需要的对象的类型名称，`getShape(const std::string& type)` 函数将会调用指定类型的 `clone()` 函数并返回副本对象的智能指针。

### 步骤四

在 `main()` 函数中，我们使用 ShapeCache 类来获取存储在哈希表中的形状的克隆：

```cpp
int main() {
	ShapeCache cache;

	auto rectangle = cache.getShape("Rectangle");
	std::cout << "Shape: " << rectangle->getType() << std::endl;
	rectangle->render();

	auto ellipse = cache.getShape("Ellipse");
	std::cout << "\n\nShape: " << ellipse->getType() << std::endl;
	ellipse->render();
}
```

### 步骤五

执行程序，输出结果：

```plain
Shape: Rectangle
Inside Rectangle::render() method.


Shape: Ellipse
Inside Ellipse::render() method.
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 当我们的对象结构比较复杂（比如它有比较多的字段、比较多的状态），而其初始状态通常又不是最理想的使用对象的状态时，我们可以考虑使用原型模式去拷贝一个已经达到理想状态的对象以创建副本。
* 在实际工程中，使用原型模式的时候可能并不多。
* 原型模式同样用于隔离类对象的使用者和具体类型（易变类）之间的耦合关系，它同样要求这些 “易变类” 拥有 “稳定的接口”。
* 原型模式对于 “如何创建易变类的实体对象” 采用 “原型克隆” 的方法来做，它使得我们可以非常灵活地动态创建 “拥有某些稳定接口” 的新对象 —— 所需工作仅仅是注册一个新类的对象（即原型），然后在任何需要的地方 `clone()`。
* 原型模式中的 `clone()` 方法可以利用某些框架中的序列化来实现深拷贝。

---

[下一篇](../Builder%20Pattern/README.md)