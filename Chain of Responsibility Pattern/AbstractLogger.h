#ifndef ABSTRACTLOGGER_H
#define ABSTRACTLOGGER_H

#include <string>

using namespace std;

/// <summary>
/// ����ļ�¼����
/// </summary>
class AbstractLogger
{

protected:
	/// <summary>��־�ȼ�</summary>
	int level;
	/// <summary>�������е���һ��Ԫ��</summary>
	AbstractLogger* nextLogger = nullptr;
	/// <summary>
	/// �����ӡ��־��Ϣ����
	/// </summary>
	/// <param name="message">��־��Ϣ</param>
	virtual void write(string message) = 0;

public:
	const static int INFO = 1;
	const static int DEBUG = 2;
	const static int ERROR = 3;
	inline AbstractLogger(int _level) : level(_level) {}
	/// <summary>
	/// ������һ����¼��
	/// </summary>
	/// <param name="_nextLogger">����ļ�¼���� AbstractLogger ��ָ��</param>
	inline void setNextLogger(AbstractLogger* _nextLogger) {
		this->nextLogger = _nextLogger;
	}
	/// <summary>
	/// ��¼��־��Ϣ�����������ǰ��¼������־�ȼ������ڲ������ݵ���־�ȼ������ӡ����־��Ϣ����������������������־��¼������
	/// </summary>
	/// <param name="_level">��־�ȼ�</param>
	/// <param name="message">��־��Ϣ</param>
	inline void logMessage(int _level, string message) {
		if (level <= _level) {
			write(message);
		}
		if (nextLogger != nullptr) {
			nextLogger->logMessage(_level, message);
		}
	}
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~AbstractLogger() {}
};

#endif // !ABSTRACTLOGGER_H