#include "ChatRoom.h"
#include "User.h"		
/**
 * 在 ChatRoom.h 中我们使用前向声明解决循环依赖问题；在 ChatRoom.cpp 中我们继续 #include "User.h"，以便编译器正确调用其成员函数
 * 更好的解决办法请参考：<https://blog.csdn.net/u010330109/article/details/120800927>
 * 但是这里为了更好地展示「中介者模式」所以不编写额外的优化代码了
 */

void ChatRoom::showMessage(User user, std::string message) {
	// C++ 获取当前时间参考：<https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c>
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	char str[26];
	ctime_s(str, sizeof str, &end_time);
	// `ctime_s` 函数会在生成的字符串末尾添加一个换行符。我们可以使用 `std::string` 的 `erase` 函数来移除它。
	std::string time_str(str);
	time_str.erase(std::remove(time_str.begin(), time_str.end(), '\n'), time_str.end());
	std::cout << time_str << " [" << user.getName() << "] : " << message << std::endl;
}