[上一篇](../Facade%20Pattern/README.md)

---

# 代理模式 Proxy

## 1、动机

* 在面向对象系统中，有些对象由于某种原因（比如对象创建的开销很大，或者某些操作需要安全控制，或者需要进程外的访问等），直接访问会给使用者、或者系统结构带来很多麻烦。
* 如何在不失去透明操作对象的同时来管理 / 控制这些对象特有的复杂性？增加一层间接层是软件开发中常见的解决方式。

> 在代理模式（Proxy Pattern）中，一个类代表另一个类的功能。这种类型的设计模式属于结构型模式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>为其他对象提供一种代理以控制对这个对象的访问。</dd>
    <dt>关键代码</dt>
    <dd>实现与被代理类组合。</dd>
</dl>

---

## 3、实现

### 步骤一

首先我们创建一个接口 Image 表示一张图片：

```cpp
class Image
{

public:
	virtual void display() = 0;
	virtual ~Image() {}
};
```

> Image 包含一个纯虚成员函数 `display()` 用于显示一张图片。

### 步骤二

接下来我们创建实现了 Image 抽象类的实体类 RealImage，其扮演被代理类的角色，其将重写虚函数以实现功能：

```cpp
class RealImage :
	public Image
{

private:
	// 图片文件名称
	std::string fileName;

public:
	inline RealImage(std::string _fileName) : fileName(_fileName) {
		loadFromDisk(_fileName);
	}
	inline virtual void display() override {
		std::cout << "Displaying " << fileName << std::endl;
	}
	inline void loadFromDisk(std::string _fileName) {
		std::cout << "Loading " << _fileName << std::endl;
	}
};
```

> RealImage 新增了一个成员函数 `loadFromDisk(std::string _fileName)` 用于从磁盘加载图片文件。在 RealImage 构造函数中我们调用该方法以在对象创建时从磁盘加载图片文件。

### 步骤三

接下来我们创建一个代理类 ProxyImage，其同样继承自 Image 抽象类，并且其内部通过**组合**的方式拥有一个 RealImage 对象。ProxyImage 是针对 RealImage 的一个代理，将减少 RealImage 对象加载的内存占用。

我们的 ProxyImage 类如下：

```cpp
class ProxyImage :
	public Image
{

private:
	RealImage* realImage = nullptr;
	std::string fileName;

public:
	inline ProxyImage(std::string _fileName) : fileName(_fileName) {}
	inline virtual void display() override {
		if (realImage == nullptr) {
			realImage = new RealImage(fileName);
		}
		realImage->display();
	}
};
```

> 当然有些时候我们的代理类可能无法直接组合一个被代理对象，而是需要一些更复杂的方式去访问被代理对象。但无论如何，这些复杂的事儿可以交给代理类来管理 / 控制。
>
> 我们的 ProxyImage 类很简单，这是为了方便演示。但在实际生产中，代理类可能会很复杂，而且往往是使用一些工具来生成。

> 💬 举一个现实生活中的例子就是当我们想要购买一件外国公司的产品时，我们通常不是直接去找原厂家购买，而是去寻找国内的代理商。

### 步骤四

在 `main()` 函数中，当被请求时，使用 ProxyImage 来获取 RealImage 类的对象：

```cpp
int main() {
	Image* image = new ProxyImage("test_10mb.jpg");

	// 图像将从磁盘加载
	image->display();
	std::cout << std::endl;
	// 图像不需要从磁盘加载
	image->display();
}
```

### 步骤五

执行程序，输出结果：

```plain
Loading test_10mb.jpg
Displaying test_10mb.jpg

Displaying test_10mb.jpg
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* “增加一层间接层” 是软件系统中对许多复杂问题的一种常见解决方法。在面向对象系统中，直接使用某些对象会带来很多问题，作为间接层的代理对象便是解决这一问题的常用手段。
* 具体代理模式的实现方法、实现[粒度](https://zhuanlan.zhihu.com/p/65220106)都相差很大。有些可能对单个对象做细粒度的控制，如 [copy-on-write](https://zhuanlan.zhihu.com/p/452676926) 技术；有些可能对组件模块提供抽象代理层，在架构层次对对象做代理。
* 代理模式并不一定要求保持接口完整的一致性，只要能够实现间接控制，有时候损及一些透明性是可以接受的。
* 代理模式应用非常广泛，包括分布式系统、各种 AOP 框架等等，都大量使用了代理模式。

---

[下一篇](../Adapter%20Pattern/README.md)