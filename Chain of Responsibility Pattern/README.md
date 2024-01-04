[上一篇](../Iterator%20Pattern/README.md)

---

# 责任链模式 Chain of Responsibility

## 1、动机

* 在软件构建过程中，一个请求可能被多个对象处理，但是每个请求在运行时只能有一个接收者。如果显式指定，将必不可少地带来请求发送者与接收者的紧耦合。
* 如何使请求的发送者不需要指定具体的接收者？让请求的接收者自己在运行时决定是否处理请求，从而使两者解耦。

> 责任链模式，又称为**职责链模式**。为请求创建了一个接收者对象的链。这种模式给予请求的类型，对请求的发送者和接收者进行解耦。这种类型的设计模式属于行为型模式。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>避免请求发送者与接收者耦合在一起，让多个对象都有可能接收请求，将这些对象连接成一条链，并且沿着这条链传递请求，直到有对象处理它为止。</dd>
    <dt>关键代码</dt>
    <dd>请求接收者内部聚合它自己，在请求里判断是否合适，如果没达到条件则向下传递，向谁传递之前设置进去。</dd>
</dl>

---

## 3、实现

我们将尝试实现一个简易的日志系统，带有详细的日志记录级别。日志记录器将会根据日志请求的级别决定是否处理日志请求。

### 步骤一

首先我们创建抽象的记录器类 AbstractLogger，其将扮演**请求接收者**的角色：

```cpp
class AbstractLogger
{

protected:
	// 记录器级别
	int level;
	// 责任链中的下一个元素
	AbstractLogger* nextLogger = nullptr;

	// 打印日志消息
	virtual void write(string message) = 0;

public:
	const static int INFO = 1;
	const static int DEBUG = 2;
	const static int ERROR = 3;
	inline AbstractLogger(int _level) : level(_level) {}

	inline void setNextLogger(AbstractLogger* _nextLogger) {
		this->nextLogger = _nextLogger;
	}

	inline void logMessage(int _level, string message) {
		if (level <= _level) {
			write(message);
		}
		if (nextLogger != nullptr) {
			nextLogger->logMessage(_level, message);
		}
	}

	virtual ~AbstractLogger() {}
};
```

> AbstractLogger 包含一些成员函数，其中：
> * `setNextLogger(AbstractLogger* _nextLogger)`：用于设置下一个记录器；
> * `logMessage(int _level, string message)`：用于处理日志记录请求。如果当前记录器的日志等级不大于参数传递的日志等级，则打印该日志消息；否则沿着责任链传递日志记录的请求。
>
> AbstractLogger 包含一些成员变量，其中：
> * `level`：当前记录器的等级，该字段指定了记录器需要处理日志记录请求的阈值级别；
> * `nextLogger`：指向责任链中的下一个请求接收者。以此我们可以将多个接收者对象连接成一条链。这也就是***关键代码***中提到的 “请求接收者内部聚合它自己”。

### 步骤二

接下来我们创建实现了 AbstractLogger 的实体记录器类 ConsoleLogger、FileLogger 以及 ErrorLogger。它们将重写抽象类的方法以实现打印日志消息的功能：

```cpp
class ConsoleLogger :
	public AbstractLogger
{

protected:
	inline virtual void write(string message) override {
		std::cout << "Standard Console::Logger: " << message << std::endl;
	}

public:
	ConsoleLogger(int _level) : AbstractLogger(_level) {}
};
```

```cpp
class FileLogger :
	public AbstractLogger
{

protected:
	inline virtual void write(string message) override {
		std::cout << "File::Logger: " << message << std::endl;
	}

public:
	FileLogger(int _level) : AbstractLogger(_level) {}
};
```

```cpp
class ErrorLogger :
	public AbstractLogger
{

protected:
	inline virtual void write(string message) override {
		std::cout << "Error Console::Logger: " << message << std::endl;
	}

public:
	ErrorLogger(int _level) : AbstractLogger(_level) {}
};
```

### 步骤三

在 main.cpp 中，`getChainOfLoggers()` 函数为请求创建一个接收者对象的链；在 `main()` 函数内，请求将沿着链传递：

```cpp
AbstractLogger* getChainOfLoggers() {
	AbstractLogger* errorLogger = new ErrorLogger(AbstractLogger::ERROR);
	AbstractLogger* fileLogger = new FileLogger(AbstractLogger::DEBUG);
	AbstractLogger* consoleLogger = new ConsoleLogger(AbstractLogger::INFO);

	errorLogger->setNextLogger(fileLogger);
	fileLogger->setNextLogger(consoleLogger);

	return errorLogger;
}

int main() {
	AbstractLogger* loggerChain = getChainOfLoggers();

	loggerChain->logMessage(AbstractLogger::INFO, "This is an information.");

	loggerChain->logMessage(AbstractLogger::DEBUG,
		"This is a debug level information.");

	loggerChain->logMessage(AbstractLogger::ERROR,
		"This is an error information.");
}
```

### 步骤四

执行程序，输出结果：

```plain
Standard Console::Logger: This is an information.
File::Logger: This is a debug level information.
Standard Console::Logger: This is a debug level information.
Error Console::Logger: This is an error information.
File::Logger: This is an error information.
Standard Console::Logger: This is an error information.
```

### 步骤五

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 责任链模式的应用场合在于 “一个请求可能有多个接收者，但是最后真正的接收者只有一个”。这时候请求发送者与接收者的耦合有可能出现 “变化脆弱” 的症状，责任链的目的就是将二者解耦，从而更好地应对变化。
* 应用了责任链模式后，对象的职责分派将更具灵活性。我们可以在**运行时动态**添加 / 修改请求的处理职责。
* 如果请求传递到责任链的末尾仍得不到处理，应该有一个合理的缺省机制。这也是每一个接收者对象的责任，而不是发出请求的对象的责任。

---

[下一篇](../Command%20Pattern/README.md)