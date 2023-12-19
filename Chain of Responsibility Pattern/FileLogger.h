#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "AbstractLogger.h"
#include <string>
#include <iostream>

using namespace std;

/// <summary>
/// ʵ�ֳ����¼���� AbstractLogger ��ʵ���¼���� FileLogger
/// </summary>
class FileLogger :
	public AbstractLogger
{

protected:
	/// <summary>
	/// ʵ�ֻ���Ĵ����ӡ��־��Ϣ����
	/// </summary>
	/// <param name="message">��־��Ϣ</param>
	inline virtual void write(string message) override {
		std::cout << "File::Logger: " << message << std::endl;
	}

public:
	FileLogger(int _level) : AbstractLogger(_level) {}
};

#endif // !FILELOGGER_H