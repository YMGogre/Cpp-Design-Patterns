#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "AbstractLogger.h"
#include <string>
#include <iostream>

using namespace std;

/// <summary>
/// 实现抽象记录器类 AbstractLogger 的实体记录器类 ConsoleLogger
/// </summary>
class ConsoleLogger :
	public AbstractLogger
{

protected:
	/// <summary>
	/// 实现基类的纯虚打印日志消息函数
	/// </summary>
	/// <param name="message">日志消息</param>
	inline virtual void write(string message) override {
		std::cout << "Standard Console::Logger: " << message << std::endl;
	}

public:
	ConsoleLogger(int _level) : AbstractLogger(_level) {}
};

#endif // !CONSOLELOGGER_H