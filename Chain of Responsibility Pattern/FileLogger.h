#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "AbstractLogger.h"
#include <string>
#include <iostream>

using namespace std;

/// <summary>
/// 实现抽象记录器类 AbstractLogger 的实体记录器类 FileLogger
/// </summary>
class FileLogger :
	public AbstractLogger
{

protected:
	/// <summary>
	/// 实现基类的纯虚打印日志消息函数
	/// </summary>
	/// <param name="message">日志消息</param>
	inline virtual void write(string message) override {
		std::cout << "File::Logger: " << message << std::endl;
	}

public:
	FileLogger(int _level) : AbstractLogger(_level) {}
};

#endif // !FILELOGGER_H