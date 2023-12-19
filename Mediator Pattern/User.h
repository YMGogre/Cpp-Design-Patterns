#ifndef USER_H
#define USER_H

#include <string>
#include "ChatRoom.h"

/// <summary>
/// User ¿‡
/// </summary>
class User
{

private:
	std::string name;

public:
	inline std::string getName() {
		return name;
	}
	inline void setName(std::string _name) {
		name = _name;
	}
	User(std::string _name) : name(_name) {}
	inline void sendMessage(std::string message) {
		ChatRoom::showMessage(*this, message);
	}
};

#endif // !USER_H