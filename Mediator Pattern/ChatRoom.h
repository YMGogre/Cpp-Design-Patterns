#ifndef CHATROOM_H
#define CHATROOM_H

#include <iostream>
#include <string>
#include <chrono>

class User;		// ʹ��ǰ�������Ա���ѭ������

/// <summary>
/// �н��� ChatRoom
/// </summary>
class ChatRoom
{

public:
	/// <summary>
	/// ��ʾָ���û���������Ϣ
	/// </summary>
	/// <param name="user">�û�</param>
	/// <param name="message">��Ϣ</param>
	static void showMessage(User user, std::string message);
};

#endif // !CHATROOM_H