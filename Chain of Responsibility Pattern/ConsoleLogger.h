#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "AbstractLogger.h"
#include <string>
#include <iostream>

using namespace std;

/// <summary>
/// ʵ�ֳ����¼���� AbstractLogger ��ʵ���¼���� ConsoleLogger
/// </summary>
class ConsoleLogger :
	public AbstractLogger
{

protected:
	/// <summary>
	/// ʵ�ֻ���Ĵ����ӡ��־��Ϣ����
	/// </summary>
	/// <param name="message">��־��Ϣ</param>
	inline virtual void write(string message) override {
		std::cout << "Standard Console::Logger: " << message << std::endl;
	}

public:
	ConsoleLogger(int _level) : AbstractLogger(_level) {}
};

#endif // !CONSOLELOGGER_H