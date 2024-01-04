[上一篇](../Composite%20Pattern/README.md)

---

# 迭代器模式 Iterator

## 1、动机

* 在软件构建过程中，集合对象内部结构常常变化各异。但对于这些集合对象，我们希望在不暴露其内部结构的同时，可以让外部客户代码透明地访问其中包含的元素；同时这种 “透明遍历” 也为 “同一种算法在多种集合对象上进行操作” 提供了可能。
* 使用面向对象技术将这种遍历机制抽象为 “迭代器对象” 为 “应对变化中的集合对象” 提供了一种优雅的方式。

> 迭代器模式是非常常用的设计模式。这种模式用于顺序访问集合对象的元素，不需要知道集合对象的底层表示。迭代器模式属于行为型模式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>提供一种方法顺序访问一个聚合对象中各个元素, 而又无须暴露该对象的内部表示。</dd>
    <dt>关键代码</dt>
    <dd>定义接口：hasNext, next。</dd>
</dl>

---

## 3、实现

### 步骤一

我们首先创建一个叙述导航方法的迭代器 Iterator 接口。Iterator 同时也是一个[类模板](https://blog.csdn.net/YMGogre/article/details/126952858#t31)：

```cpp
template <typename T>
class Iterator
{
protected:
	// 容器对象的引用
	Container<T>& container;
	// 项的索引
	size_t index = 0;

public:
	Iterator(Container<T>& _container) : container(_container) {}
	virtual bool hasNext() = 0;
	virtual T next() = 0;
	virtual ~Iterator() {}
};
```

> Iterator 包含一些纯虚成员函数。其中：
> * `hasNext()`：判断集合中是否还有下一项；
> * `next()`：获取集合中的下一项。
>
> 此外 Iterator 包含一些成员变量。其中：
> * `container`：我们需要在迭代器内部包含一个容器对象的引用，这样迭代器才能知道集合的内部信息。

### 步骤二

接下来我们创建抽象容器类 Container：

```cpp
template <typename T>
class Container
{
protected:
	/// <summary>项的集合</summary>
	std::vector<T> items;

public:
	Container(const std::vector<T>& init_vec) : items(init_vec) {}
	virtual std::unique_ptr<Iterator<T>> getIterator() = 0;
	virtual ~Container() {}
	inline size_t size() const { return items.size(); }
	// 重载 [] 运算符
	inline T& operator[](int index){ return items[index]; }
};
```

> Container 包含一些成员函数。其中：
> * `getIterator()`：用于获取迭代器；
> * `size()`：获取容器的大小。

### 步骤三

接下来我们创建实现了 Container 接口的实体类 NameRepository。其还将负责实现 Iterator 接口（因为容器和迭代器关系密切），所以该类有实现了 Iterator 接口的内部类 NameIterator。

我们的 NameRepository 类如下：

```cpp
class NameRepository :
	public Container<std::string>
{

private:
	class NameIterator :
		public Iterator<std::string>
	{

	public:
		NameIterator(Container<std::string>& _container) : Iterator(_container) {}
		inline virtual bool hasNext() override {
			return index < container.size();
		}
		inline virtual std::string next() override {
			if (this->hasNext()) {
				return container[index++];
			}
			return std::string();
		}
	};

public:
	NameRepository(const std::vector<std::string>& init_vec) : Container{ init_vec } {}
	inline virtual std::unique_ptr<Iterator<std::string>> getIterator() override {
		return std::make_unique<NameIterator>(*this);
	}
};
```

### 步骤四

在 `main()` 函数中，我们使用 NameRepository 来获取迭代器，并打印名字：

```cpp
int main() {
	std::vector<std::string> names = { "Robert" , "John" ,"Julie" , "Lora" };
	NameRepository namesRepository(names);
	std::unique_ptr<Iterator<std::string>> iter = namesRepository.getIterator();
	for (iter; iter->hasNext();) {
		std::string name = iter->next();
		std::cout << "Name : " << name << std::endl;
	}
}
```

### 步骤五

执行程序，输出结果：

```plain
Name : Robert
Name : John
Name : Julie
Name : Lora
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 随着 STL 标准模板库以及泛型编程的发展，C++ 迭代器模式这种面向对象的实现（多态）逐渐有一些过时了，不过其思想仍然值得学习。
* 迭代抽象：访问一个聚合对象的内容而无需暴露它的内部表示。

    > 迭代器不关心聚合对象内部是如何实现的：不管是链表还是树形还是堆或是栈实现的，迭代器都不关心。

* 迭代多态：为遍历不同的集合结构提供了一个统一的接口，从而支持同样的算法在不同的集合结构上进行操作。
* 迭代器的健壮性考虑：遍历的同时更改迭代器所在的集合结构，会导致问题。

---

[下一篇](../Chain%20of%20Responsibility%20Pattern/README.md)