[上一篇](../Visitor%20Pattern/README.md)

---

# 💠 “领域规则”模式

在特定领域中，某些变化虽然频繁，但可以抽象为某种规则。这时候，结合特定领域，将问题抽象为语法规则，从而给出在该领域下的一般性解决方案。

典型模式：
* 解释器模式 Interpreter

# 解释器模式 Interpreter



## 1、动机

* 在软件构建过程中，如果某一特定领域的问题比较复杂，类似的结构不断重复出现，如果使用普通的编程方式来实现将面临非常频繁的变化。
* 在这种情况下，将特定领域的问题表达为某种语法规则下的句子，然后构建一个解释器来解释这样的句子，从而达到解决问题的目的。

> 解释器模式提供了评估语言的语法或表达式的方式，它属于行为型模式。这种模式实现了一个表达式接口，该接口解释一个特定的上下文。这种模式被用在 SQL 解析、符号处理引擎等。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>给定一个语言，定义它的文法表示，并定义一个解释器，这个解释器使用该标识来解释语言中的句子。</dd>
    <dt>关键代码</dt>
    <dd>解释器模式的关键代码主要包含以下部分：<ul><li>抽象表达式：定义解释器的接口，约定解释器的解释操作，主要包含解释方法 <code>interpret()</code>。</li><li>终结符表达式：实现抽象表达式要求的接口，文法中每一个终结符都有其对应的具体终结表达式。</li><li>非终结符表达式：文法中的每一个规则都需要一个具体的非终结符表达式，一般表示文法中的运算符或者一些关键字。</li><li>上下文：这个角色用来存放终结符对应的具体的位置。</li></ul></dd>
</dl>

---

## 3、实现

### 步骤一

首先我们创建一个表达式接口 Expression：

```cpp
class Expression
{

public:
	/// <summary>
	/// 纯虚解释函数
	/// </summary>
	/// <param name="context">待解释的上下文</param>
	/// <returns>是否解释成功</returns>
	virtual bool interpret(std::string context) = 0;
	
	virtual ~Expression() {}
};
```

### 步骤二

接下来我们创建实现了 Expression 类的实体表达式类 TerminalExpression、OrExpression 和 AndExpression。其中 TerminalExpression 终结符表达式作为上下文中主要解释器，OrExpression 以及 AndExpression 是非终结符表达式用于创建组合表达式。

```cpp
class TerminalExpression :
	public Expression
{

private:
	// 当前表达式的数据
	std::string data;

public:
	inline TerminalExpression(std::string _data) : data(_data) {}

	inline virtual bool interpret(std::string context) override {
		if (context.find(data) != std::string::npos) {
			return true;	// 如果传入的上下文中包含当前表达式，则认为可以解释当前上下文，返回 true
		}
		return false;
	}
};
```

> 我们可以把 TerminalExpression 类当作是一个关键字检测表达式类，如果当前传入的上下文中包含当前表达式，则认为可以解释当前上下文，`interpret(std::string context)` 返回 `true`。

```cpp
class OrExpression :
	public Expression
{

private:
	std::shared_ptr<Expression> expr1;
	std::shared_ptr<Expression> expr2;

public:
	inline OrExpression(std::shared_ptr<Expression> _expr1, std::shared_ptr<Expression> _expr2) :
		expr1(_expr1), expr2(_expr2) {}

	inline virtual bool interpret(std::string context) override {
		return expr1->interpret(context) || expr2->interpret(context);
	}
};
```

```cpp
class AndExpression :
	public Expression
{

private:
	std::shared_ptr<Expression> expr1;
	std::shared_ptr<Expression> expr2;

public:
	inline AndExpression(std::shared_ptr<Expression> _expr1, std::shared_ptr<Expression> _expr2) :
		expr1(_expr1), expr2(_expr2) {}

	inline virtual bool interpret(std::string context) override {
		return expr1->interpret(context) && expr2->interpret(context);
	}
};
```

### 步骤三

在 `main()` 函数中，我们使用 Expression 类来创建规则，并尝试解析一些上下文：

```cpp
// 规则：Robert 和 John 是男性
static std::shared_ptr<Expression> getMaleExpression() {
	std::shared_ptr<Expression> robert = std::make_shared<TerminalExpression>("Robert");
	std::shared_ptr<Expression> john = std::make_shared<TerminalExpression>("John");
	return std::make_shared<OrExpression>(robert, john);
}

// 规则：Julie 是一位已婚的女性
static std::shared_ptr<Expression> getMarriedWomanExpression() {
	std::shared_ptr<Expression> julie = std::make_shared<TerminalExpression>("Julie");
	std::shared_ptr<Expression> married = std::make_shared<TerminalExpression>("Married");
	return std::make_shared<AndExpression>(julie, married);
}

int main() {
	std::shared_ptr<Expression> isMale = getMaleExpression();
	std::shared_ptr<Expression> isMarriedWoman = getMarriedWomanExpression();

	std::cout << "John is male? " << std::boolalpha << isMale->interpret("John") << std::endl;
	std::cout << "Julie is a married women? " << std::boolalpha << isMarriedWoman->interpret("Married Julie") << std::endl;
}
```

### 步骤四

执行程序，输出结果：

```plain
John is male? true
Julie is a married women? true
```

### 步骤五

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 解释器模式的应用场合是解释器模式应用中的难点，只有满足 “业务规则频繁变化，且类似的结构不断重复出现，并且容易抽象为语法规则的问题” 才适合使用解释器模式。
* 使用解释器模式来表示文法规则，从而可以使用面向对象技巧来方便地 “扩展” 文法。
* 解释器模式比较适合简单的文法表示，对于复杂的文法表示，解释器模式会产生比较大的类层次结构，需要求助于语法分析生成器这样的标准工具。

---

[下一篇](../Filter%20Pattern/README.md)