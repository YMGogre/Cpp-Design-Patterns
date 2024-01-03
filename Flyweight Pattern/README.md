[上一篇](../Singleton%20Pattern/README.md)

---

# 享元模式 Flyweight

## 1、动机

* 在软件系统采用纯粹对象方案的问题在于大量[细粒度](https://www.zhihu.com/question/299171510 "如何理解fine-grained和coarse-grained？- 知乎")的对象会很快充斥在系统中，从而带来很高的运行时代价 —— 主要指内存需求方面的代价。
* 如何在避免大量细粒度对象问题的同时，让外部客户程序仍然能够透明地使用面向对象的方式来进行操作？

> 享元模式主要用于减少创建对象的数量，以减少内存占用和提高性能。这种类型的设计模式属于结构型模式，它提供了减少对象数量从而改善应用所需的对象结构的方式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>运用共享技术有效地支持大量细粒度的对象。</dd>
    <dt>关键代码</dt>
    <dd>使用关联容器存储这些对象。</dd>
</dl>

---

## 3、实现

### 步骤一

首先我们创建一个接口 Shape，其将作为抽象享元类：

```cpp
class Shape {
public:
	virtual void render() = 0;
	virtual ~Shape() {};
};
```

### 步骤二

接下来创建实现 Shape 的实体类 Circle：

```cpp
class Circle :
	public Shape
{

private:
	std::string color;
	int x = 0;
	int y = 0;
	int radius = 0;

public:
	inline Circle(std::string _color) : color(_color) {};

	inline void setX(int _x) {
		x = _x;
	}
	inline void setY(int _y) {
		y = _y;
	}
	inline void setRadius(int _radius) {
		radius = _radius;
	}
	inline virtual void render() override{
		std::cout << "Circle: Render() [Color : " << color << ", x : "
			<< x << ", y : " << y << ", radius : " << radius << "]" <<std::endl;
	}
};
```

> Circle 包含一些基本的成员变量作为其属性。其中：
> * `color`：圆的颜色；
> * `x`、`y`：圆在屏幕坐标系下的坐标；
> * `radius`：圆的半径。

### 步骤三

我们将 Circle 的 `color` 字段作为其唯一标识符。当我们想要创建一个 Circle 对象时，如果内存中已有同颜色的 Circle 对象，则返回内存中已有的那个对象。

接下来我们创建一个享元工厂 ShapeFactory，其使用了一个关联容器存储这些 Circle 对象。对外其提供了生成基于给定信息的实体类的对象的功能。

我们的 ShapeFactory 类如下：

```cpp
class ShapeFactory
{

private:
	static std::map<std::string, Shape*> circleMap;

public:
	static inline Shape* getCircle(std::string _color) {
		if (circleMap.find(_color) != circleMap.end()) {
			return circleMap[_color];
		}
		else {
			Shape* fly = new Circle(_color);
			circleMap.insert(std::pair<std::string, Shape*>(_color, fly));
			std::cout << "Creating circle of color : " << _color << std::endl;	// 在新建对象时打印输出
			return fly;
		}
	}
};
```

> ShapeFactory 使用 `std::map` 存储这些 Circle 对象，`std::map` 的内部实现通常是红黑树；当然你也可以使用基于哈希函数的关联容器 `std::unordered_map`。
>
> 选择哪一个关联容器取决于具体需求。如果需要保持元素顺序，可以考虑使用 `std::map`；如果看重查找效率，可以考虑使用 `std::unordered_map`。

### 步骤四

在 `main()` 函数中，我们使用随机数创建 Circle 对象：

```cpp
std::string colors[] = { "Red", "Green", "Blue", "White", "Black" };
std::map<std::string, Shape*> ShapeFactory::circleMap;
std::random_device rd;		// 用于获取随机数的设备
std::default_random_engine eng(rd());	// 随机数引擎
std::uniform_real_distribution<double> distr1(0, 1);	// [0, 1) 半开区间均匀分布的随机数生成器<https://zh.cppreference.com/w/cpp/numeric/random/uniform_real_distribution>
std::uniform_int_distribution<int> distr2(1, 100);		// [1, 100] 闭区间均匀分布的随机数生成器<https://zh.cppreference.com/w/cpp/numeric/random/uniform_int_distribution>

std::string getRandomColor();
int getRandomX();
int getRandomY();

int main() {
	for (int i = 0; i < 20; i++) {
		auto circle = static_cast<Circle*>(ShapeFactory::getCircle(getRandomColor()));
		circle->setX(getRandomX());
		circle->setY(getRandomY());
		circle->setRadius(100);
		circle->render();
	}
}

std::string getRandomColor() {
	auto length = sizeof(colors) / sizeof(colors[0]);
	return colors[(int)(distr1(eng) * length)];
}
int getRandomX() {
	return distr2(eng);
}
int getRandomY() {
	return distr2(eng);
}
```

在 main.cpp 中，我们使用了 C++11 的随机数生成器。它在本例中的作用只是为了生成一些随机的 Circle 对象，故这里不再展开。

### 步骤五

执行程序，输出结果：

```plain
Creating circle of color : Blue
Circle: Render() [Color : Blue, x : 38, y : 59, radius : 100]
Circle: Render() [Color : Blue, x : 29, y : 38, radius : 100]
Creating circle of color : Red
Circle: Render() [Color : Red, x : 6, y : 17, radius : 100]
Creating circle of color : Black
Circle: Render() [Color : Black, x : 23, y : 30, radius : 100]
Creating circle of color : White
Circle: Render() [Color : White, x : 14, y : 81, radius : 100]
Circle: Render() [Color : Blue, x : 28, y : 77, radius : 100]
Circle: Render() [Color : Black, x : 72, y : 78, radius : 100]
Circle: Render() [Color : Black, x : 75, y : 88, radius : 100]
Circle: Render() [Color : White, x : 67, y : 20, radius : 100]
Circle: Render() [Color : Black, x : 22, y : 76, radius : 100]
Circle: Render() [Color : Black, x : 22, y : 26, radius : 100]
Circle: Render() [Color : White, x : 38, y : 90, radius : 100]
Circle: Render() [Color : Black, x : 13, y : 94, radius : 100]
Circle: Render() [Color : Black, x : 36, y : 34, radius : 100]
Circle: Render() [Color : White, x : 45, y : 2, radius : 100]
Circle: Render() [Color : Black, x : 19, y : 83, radius : 100]
Circle: Render() [Color : White, x : 47, y : 75, radius : 100]
Circle: Render() [Color : Red, x : 2, y : 64, radius : 100]
Circle: Render() [Color : Red, x : 63, y : 90, radius : 100]
Creating circle of color : Green
Circle: Render() [Color : Green, x : 32, y : 22, radius : 100]
```

> 🔔 由于 Circle 对象是随机生成的，故本例的输出并不固定。

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 面向对象很好地解决了抽象性的问题，但是作为一个运行在机器中的程序实体，我们需要考虑对象的代价问题。享元模式主要解决面向对象的代价问题，一般不涉及面向对象的抽象性问题。
* 享元模式采用对象共享的做法来降低系统中对象的个数，从而降低细粒度对象给系统带来的内存压力。在具体实现方面，要注意对象状态的处理。

    > 一般来讲，共享对象尽可能只读。

* 对象的数量太大从而导致对象内存开销加大 —— 什么样的数量才算大？这需要我们仔细地根据具体应用情况进行评估，而不能凭空臆断。

---

[下一篇](../Facade%20Pattern/README.md)