[上一篇](../深入理解设计模式/深入理解设计模式.md)

---

# 模板（方法）模式 Template (Method)

> 请注意，笔者在名称中使用了括号。这意味着在某些地方可能会将该模式称为“**模板模式 Template**”。

## 1、动机

* 在软件构件过程中，对于某一项任务，它常常有**稳定**的整体操作结构，但各个子步骤却有很多**改变**的需求，或者由于固有的原因（比如框架和应用之间的关系）而无法和任务的整体结构同时实现。
* 如何在确定稳定操作结构的前提下，来灵活应对各个子步骤的变化或者晚期实现需求？

> 在模板（方法）模式中，一个抽象类公开定义了执行它的方法的方式/模板。它的子类可以按需要重写方法实现，但调用将以抽象类中定义的方式进行。这种类型的设计模式属于行为型模式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。</dd>
    <dt>关键代码</dt>
    <dd>模板方法在抽象类实现，其他步骤在子类实现。</dd>
</dl>

---

## 3、实现

### 步骤一

我们将创建一个抽象游戏类 Game。它包含一些基础的成员函数，比如：
* `initialize()` 初始化游戏
* `startPlay()` 开始游戏
* `endPlay()` 结束游戏

此外，Game 抽象类公开定义了执行它的方法的方式 / 模板，模板方法名为 `play()`。模板方法被设置为 `final`，这样它就不会被重写。

我们的 Game 类如下：
```cpp
class Game
{

public:
	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;

	/**
     * 模板方法提供了「游玩游戏」的模板，
     * 即按如下顺序执行它的成员函数即可 
     */
	inline virtual void play() final {
		// 初始化游戏
		initialize();

		// 开始游戏
		startPlay();

		// 结束游戏
		endPlay();
	}
	virtual ~Game() {}
};
```

> 需要注意的是，在 `play()` 函数中，我们通过 **函数名**+**括号** 的形式直接调用另一个成员函数。这种写法省略了前缀的 `this` 指针，但我们需要清楚函数的调用是通过 `this` 指针去调用的（比如：`this->initialize();`）。
>
> 而我们知道，当我们通过指针去调用函数时，对它的调用将具备多态特性。

在抽象类 Game 中，“**稳定**的整体操作结构” 就是指「游玩游戏」这一步骤操作结构。通过 `play()` 模板方法规定了该步骤操作结构就是 “先初始化游戏，再开始游戏，最后结束游戏”。实现方式就是按照步骤调用 Game 类的其他几个成员函数即可。

而 “各个子步骤却有很多**改变**的需求” 就是指对于各个不同类型的游戏，其初始化及开始和结束游戏的操作可能是不同的。所以 Game 类中将它们声明为了纯虚函数，不提供实现。这些子步骤将会延迟到派生类中实现。

### 步骤二

接下来我们创建实现了 Game 类的实体类 Cricket 和 Football，它们将重写抽象类的方法以实现子步骤（初始化游戏、开始游戏、结束游戏）：

```cpp
// 板球游戏
class Cricket :
	public Game
{

public:
	inline virtual void endPlay() override {
		std::cout << "Cricket Game Finished!" << std::endl;
	}
	inline virtual void initialize() override {
		std::cout << "Cricket Game Initialized! Start playing." << std::endl;
	}
	inline virtual void startPlay() override {
		std::cout << "Cricket Game Started. Enjoy the game!" << std::endl;
	}
};

// 足球游戏
class Football :
	public Game
{

public:
	inline virtual void endPlay() override {
		std::cout << "Football Game Finished!" << std::endl;
	}
	inline virtual void initialize() override {
		std::cout << "Football Game Initialized! Start playing." << std::endl;
	}
	inline virtual void startPlay() override {
		std::cout << "Football Game Started. Enjoy the game!" << std::endl;
	}
};
```

### 步骤三

在 `main()` 函数中，我们将使用 Game 类演示模板（方法）模式的用法：

```cpp
int main() {
	Game* game = new Cricket();
	game->play();
	delete game;

	std::cout << std::endl;

	Football football;
	Game& game2 = football;
	game2.play();
}
```

### 步骤四

执行程序，输出结果：

```plain
Cricket Game Initialized! Start playing.
Cricket Game Started. Enjoy the game!
Cricket Game Finished!

Football Game Initialized! Start playing.
Football Game Started. Enjoy the game!
Football Game Finished!
```