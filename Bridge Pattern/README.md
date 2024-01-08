[上一篇](../Decorator%20Pattern/README.md)

---

# 桥接模式 Bridge

## 1、动机

* 由于某些类型的固有的实现逻辑，使得它们具有两个变化的维度，乃至多个维度的变化。
* 如何应对这种 “多维度的变化”？如何利用面向对象技术来使得类型可以轻松地沿着两个乃至多个方向变化，而不引入额外的复杂度？

> 桥接模式是用于把抽象化与实现化解耦，使得二者可以独立变化。这种类型的设计模式属于结构型模式，它通过提供抽象化和实现化之间的桥接结构，来实现二者的解耦。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>将抽象部分与实现部分分离，使它们都可以独立的变化。</dd>
    <dt>关键代码</dt>
    <dd>抽象类依赖于实现类。</dd>
</dl>

---

## 3、实现

### 步骤一

我们将创建一个作为桥接实现的 RenderAPI 接口，它将扮演桥接模式中实现化的部分的角色：

```cpp
class RenderAPI
{

public:
	virtual void renderCircle(int radius, int x, int y) = 0;
	virtual ~RenderAPI() {}
};
```

可以看到，RenderAPI 包含一个纯虚的 `renderCircle(int radius, int x, int y)` 成员函数，它将负责**实现**「渲染一个圆形」。

### 步骤二

接下来我们创建实现了 RenderAPI 接口的实体桥接实现类 RedCircle 和 GreenCircle：

```cpp
class RedCircle :
	public RenderAPI
{

public:
	inline virtual void renderCircle(int radius, int x, int y) override {
		std::cout << "Rendering Circle[ color: red, radius: " 
			<< radius << ", x: " << x << ", y: " << y << "]" << std::endl;
	}
};
```

```cpp
class GreenCircle :
	public RenderAPI
{

public:
	inline virtual void renderCircle(int radius, int x, int y) override {
		std::cout << "Rendering Circle[ color: green, radius: "
			<< radius << ", x: " << x << ", y: " << y << "]" << std::endl;
	}
};
```

### 步骤三

接下来我们将创建抽象类 Shape，其依赖于 RenderAPI 接口。Shape 类将扮演桥接模式中抽象化的部分的角色：

```cpp
class Shape
{

protected:
	RenderAPI* renderAPI;
	inline Shape(RenderAPI* _renderAPI) : renderAPI(_renderAPI) {}

public:
	virtual void render() = 0;
	virtual ~Shape() {
		delete renderAPI;
	}
};
```

Shape 包含一个纯虚的 `render()` 成员函数，用于渲染一个形状。但在桥接模式中，Shape 派生类都不会自己实现该成员函数；相反它们将依赖于指针成员变量 `renderAPI` 来负责实现 `render()` 函数。

> 💬 以此，抽象化与实现化已经完成了解耦，二者可以独立变化。

### 步骤四

然后我们创建实现了 Shape 抽象类的实体类 Circle：

```cpp
class Circle :
	public Shape
{

private:
	int x, y, radius;

public:
	inline Circle(int _x, int _y, int _radius, RenderAPI* _renderAPI) :
		Shape(_renderAPI), x(_x), y(_y), radius(_radius) {
	}
	inline virtual void render() override {
		renderAPI->renderCircle(radius, x, y);
	}
};
```

### 步骤五

在 `main()` 函数中，我们使用 Circle 类画出不同颜色的圆：

```cpp
int main() {
	Circle redCircle(100, 100, 10, new RedCircle());
	Circle greenCircle(100, 100, 10, new GreenCircle());

	redCircle.render();
	greenCircle.render();
}
```

### 步骤六

执行程序，输出结果：

```plain
Rendering Circle[ color: red, radius: 10, x: 100, y: 100]
Rendering Circle[ color: green, radius: 10, x: 100, y: 100]
```

### 步骤七

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 桥接模式使用 “**对象间的组合关系**” 解耦了抽象和实现之间固有的绑定关系，使得抽象和实现可以沿着各自的维度来变化。所谓 “抽象和实现沿着各自的维度变化”，即 “子类化” 它们。
* 桥接模式有时候类似于多继承方案，但是多继承方案往往违背单一职责原则（即一个类只有一个变化的原因），复用性比较差。桥接模式是比多继承方案更好的解决方法。
* 桥接模式的应用一般在 “两个非常强的变化维度”，有时一个类也有多于两个的变化维度，这时可以使用桥接的扩展模式。

	> 一个变化维度用一次桥接模式。

---

[下一篇](../Factory%20Pattern/README.md)