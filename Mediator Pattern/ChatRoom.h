#ifndef CHATROOM_H
#define CHATROOM_H

#include <iostream>
#include <string>
#include <chrono>

class User;		// 使用前向声明以避免循环依赖

/// <summary>
/// 中介类 ChatRoom
/// </summary>
class ChatRoom
{

public:
	/// <summary>
	/// 显示指定用户发出的消息
	/// </summary>
	/// <param name="user">用户</param>
	/// <param name="message">消息</param>
	static void showMessage(User user, std::string message);
};

#endif // !CHATROOM_H