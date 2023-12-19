#ifndef ABSTRACTLOGGER_H
#define ABSTRACTLOGGER_H

#include <string>

using namespace std;

/// <summary>
/// 抽象的记录器类
/// </summary>
class AbstractLogger
{

protected:
	/// <summary>日志等级</summary>
	int level;
	/// <summary>责任链中的下一个元素</summary>
	AbstractLogger* nextLogger = nullptr;
	/// <summary>
	/// 纯虚打印日志消息函数
	/// </summary>
	/// <param name="message">日志消息</param>
	virtual void write(string message) = 0;

public:
	const static int INFO = 1;
	const static int DEBUG = 2;
	const static int ERROR = 3;
	inline AbstractLogger(int _level) : level(_level) {}
	/// <summary>
	/// 设置下一个记录器
	/// </summary>
	/// <param name="_nextLogger">抽象的记录器类 AbstractLogger 的指针</param>
	inline void setNextLogger(AbstractLogger* _nextLogger) {
		this->nextLogger = _nextLogger;
	}
	/// <summary>
	/// 记录日志消息函数。如果当前记录器的日志等级不大于参数传递的日志等级，则打印该日志消息；否则沿着责任链传递日志记录的请求。
	/// </summary>
	/// <param name="_level">日志等级</param>
	/// <param name="message">日志消息</param>
	inline void logMessage(int _level, string message) {
		if (level <= _level) {
			write(message);
		}
		if (nextLogger != nullptr) {
			nextLogger->logMessage(_level, message);
		}
	}
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~AbstractLogger() {}
};

#endif // !ABSTRACTLOGGER_H