[上一篇](../Strategy%20Pattern/README.md)

---

# 观察者模式 Observer

> 在某些地方可能会将该模式称为“**事件模式 Event**”。

## 1、动机

* 在软件构建过程中，我们需要为某些对象建立一种 “通知依赖关系” —— 一个对象（目标对象）的状态发生改变，所有的依赖对象（观察者对象）都将得到通知。如果这样的依赖关系过于紧密，将使软件不能很好地抵御变化。
* 使用面向对象技术，可以将这种依赖关系弱化，并形成一种稳定的依赖关系。从而实现软件体系结构的松耦合。

> 观察者模式是一种行为型设计模式，它定义了一种一对多的依赖关系，当一个对象的状态发生改变时，其所有依赖者都会收到通知并自动更新。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。</dd>
    <dt>关键代码</dt>
    <dd>在被观察类里有一个动态数组存放观察者们。</dd>
</dl>

---

## 3、实现

### 步骤一

我们将创建一个主题（被观察者）类 Subject，其维护着一个观察者 Observer 的列表。Subject 的对象是具有状态的对象，并提供了添加和通知观察者的方法。

我们的 Subject 类如下：

```cpp
class Subject
{

private:
	vector<Observer*> observers;
	int state;

public:
	inline int getState() {
		return state;
	}

    // 通知所有观察者
	inline void notifyAllObservers() {
		for (auto observer : observers) {
			observer->update();
		}
	}

	inline void setState(int _state) {
		state = _state;
		notifyAllObservers();
	}

    // 添加观察者
	inline void attach(Observer* observer) {
		observers.push_back(observer);
	}
};
```

可以看到，Subject 类包含一个 int 类型的成员变量 `state`，我们使用该成员变量表征 Subject 对象的状态。

### 步骤二

接下来我们创建抽象的观察者基类 Observer，其包含一个指向主题（被观察者）的指针成员变量，并具有一个纯虚的成员函数 `update()`，该成员函数用于更新观察者自身：

```cpp
class Observer
{

protected:
	Subject* subject;

public:
	Observer(Subject* _subject) : subject(_subject) {}
	virtual void update() = 0;
	virtual ~Observer() {}
};
```

### 步骤三

然后我们创建实现了 Observer 抽象类的实体类 BinaryObserver、OctalObserver 和 HexaObserver。它们都将在 `update()` 方法中实现各自的收到通知并更新自己的具体内容：

```cpp
class BinaryObserver :
	public Observer
{

public:
	BinaryObserver(Subject* _subject) : Observer(_subject) {
		// 将自己添加到主题（被观察者）的观察者列表中
		subject->attach(this);
	}

    // 显示主题（被观察者）的状态的二进制形式
	inline virtual void update() override {
		std::string binary = std::bitset<32>(subject->getState()).to_string();
		size_t pos = binary.find_first_not_of('0');
		if (pos != std::string::npos) {
			binary = binary.substr(pos);
		}
		std::cout << "Binary String: " << binary << std::endl;
	}
};
```

```cpp
class OctalObserver :
	public Observer
{

public:
	OctalObserver(Subject* _subject) : Observer(_subject) {
		subject->attach(this);
	}
	
    // 显示主题（被观察者）的状态的八进制形式
	inline virtual void update() override {
		std::ostringstream oss;
		oss << std::oct << subject->getState();
		std::cout << "Octal String: " << oss.str() << std::endl;
	}
};
```

```cpp
class HexaObserver :
	public Observer
{

public:
	HexaObserver(Subject* _subject) : Observer(_subject) {
		subject->attach(this);
	}

	// 显示主题（被观察者）的状态的十六进制形式
	inline virtual void update() override {
		std::ostringstream oss;
		oss << std::hex << subject->getState();
		std::cout << "Hex String: " << oss.str() << std::endl;
	}
};
```

### 步骤四

在 `main()` 函数中，我们使用主题（被观察者）和实体观察者对象来建立通知依赖关系：

```cpp
int main() {
	Subject subject;

	HexaObserver ho(&subject);
	OctalObserver oo(&subject);
	BinaryObserver bo(&subject);

	std::cout << "First state change: 15" << std::endl;
	subject.setState(15);
	std::cout << "Second state change: 10" << std::endl;
	subject.setState(10);
}
```

### 步骤五

执行程序，输出结果：

```plain
First state change: 15
Hex String: f
Octal String: 17
Binary String: 1111
Second state change: 10
Hex String: a
Octal String: 12
Binary String: 1010
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 使用面向对象的抽象，观察者模式使得我们可以独立地改变目标与观察者，从而使二者之间的依赖关系达致松耦合。
* 目标发送通知时，无需指定观察者，通知（可以携带通知信息作为参数）会自动传播。
* 观察者自己决定是否需要订阅通知，目标对象对此一无所知。
* 观察者模式是基于事件的 UI 框架中非常常用的设计模式，也是 MVC 模式的一个重要组成部分。

---

[下一篇](../Decorator%20Pattern/README.md)