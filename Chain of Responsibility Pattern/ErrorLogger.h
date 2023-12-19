#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include "AbstractLogger.h"
#include <string>
#include <iostream>

using namespace std;

/// <summary>
/// ʵ�ֳ����¼���� AbstractLogger ��ʵ���¼���� ErrorLogger
/// </summary>
class ErrorLogger :
	public AbstractLogger
{

protected:
	/// <summary>
	/// ʵ�ֻ���Ĵ����ӡ��־��Ϣ����
	/// </summary>
	/// <param name="message">��־��Ϣ</param>
	inline virtual void write(string message) override {
		std::cout << "Error Console::Logger: " << message << std::endl;
	}

public:
	ErrorLogger(int _level) : AbstractLogger(_level) {}
};

#endif // !ERRORLOGGER_H