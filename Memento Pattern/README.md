[上一篇](../State%20Pattern/README.md)

---

# 备忘录模式 Memento

## 1、动机

* 在软件构建过程中，某些对象的状态在转换过程中，可能由于某种需要，要求程序能够回溯到对象之前处于某个点时的状态。如果使用一些公有接口来让其他对象得到对象的状态，便会暴露对象的细节实现。
* 如何实现对象状态的良好保存与恢复？但同时又不会因此而破坏对象本身的封装性？

> 备忘录模式保存一个对象的某个状态，以便在适当的时候恢复对象。备忘录模式属于行为型模式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。</dd>
    <dt>关键代码</dt>
    <dd>客户不与备忘录类耦合，与备忘录管理类耦合。</dd>
</dl>

---

## 3、实现

### 步骤一

首先我们创建一个原发器类 Originator，在备忘录模式中该类扮演***希望被保存状态的那个类***的角色。为了方便演示，其只有一个状态需要被保存，那就是 `state` 字段：

```cpp
class Originator 
{
	
private:
	std::string state;

public:
	inline void setState(std::string _state) {
		state = _state;
	}
	inline std::string getState() {
		return state;
	}
	inline Memento saveStateToMemento() {
		return Memento(state);
	}
	inline void getStateFromMemento(Memento memento) {
		state = memento.getState();
	}
};
```

> Originator 包含一些成员函数。其中：
> * `saveStateToMemento()`：负责将当前 Originator 对象的状态存储到一个 Memento 备忘录对象之中，并返回那个 Memento 对象。
> * `getStateFromMemento(Memento memento)`：负责从一个 Memento 对象中获取备份状态并将当前 Originator 对象状态恢复到备份状态。

### 步骤二

接下来我们创建一个备忘录类 Memento。Memento 被设计用于专门存储 Originator 对象的状态，所以它也有一个 `state` 字段：

> 当然我们也可以采用其他手段，比如内存流或者某种能记录状态的格式化字符串或者对象序列化等等。
> 
> 只要能把 Originator 对象的状态，也就是 `state` 字段的内容给存储下来就行。

```cpp
class Memento 
{
	
private:
	// 要被恢复的对象的状态
	std::string state;

public:
	Memento(std::string _state) : state(_state) {}
	inline std::string getState() {
		return state;
	}
};
```

> 此外，Memento 还提供了成员函数 `getState()` 供 Originator 来访问。

### 步骤三

接下来我们创建一个备忘录管理者类 CareTaker，其负责管理 Memento 对象：

```cpp
class CareTaker
{

private:
	std::vector<Memento> mementoList;

public:
	inline void add(Memento state) {
		mementoList.push_back(state);
	}
	inline Memento get(int index) {
		return mementoList[index];
	}
};
```

> CareTaker 使用一个动态数组存储所有的备忘录对象并允许**附加备忘录对象**或**取得指定下标索引的备忘录对象**。

### 步骤四

在 `main()` 函数中，我们使用 CareTaker 和 Originator 对象来展示对象的状态恢复：

```cpp
int main() {
	Originator originator;
	CareTaker careTaker;
    originator.setState("State #1");
    originator.setState("State #2");
    careTaker.add(originator.saveStateToMemento());
    originator.setState("State #3");
    careTaker.add(originator.saveStateToMemento());
    originator.setState("State #4");

    std::cout << "Current State: " << originator.getState() << std::endl;
    originator.getStateFromMemento(careTaker.get(0));
    std::cout << "First saved State: " << originator.getState() << std::endl;
    originator.getStateFromMemento(careTaker.get(1));
    std::cout << "Second saved State: " << originator.getState() << std::endl;
}
```

### 步骤五

执行程序，输出结果：

```plain
Current State: State #4
First saved State: State #2
Second saved State: State #3
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 备忘录（Memento）存储原发器（Originator）对象的内部状态，在需要时恢复原发器状态。
* 备忘录模式的核心是信息隐藏，即 Originator 需要向外界隐藏信息，保持其封装性。但同时又需要将状态保持在外界（Memento）。
* 由于现代语言运行时（如 C#、Java 等）都具有相当的对象序列化支持，因此往往采用效率较高、又较容易正确实现的序列化方案来实现备忘录模式。

---

[下一篇](../Composite%20Pattern/README.md)