#include "ChatRoom.h"
#include "User.h"		
/**
 * �� ChatRoom.h ������ʹ��ǰ���������ѭ���������⣻�� ChatRoom.cpp �����Ǽ��� #include "User.h"���Ա��������ȷ�������Ա����
 * ���õĽ���취��ο���<https://blog.csdn.net/u010330109/article/details/120800927>
 * ��������Ϊ�˸��õ�չʾ���н���ģʽ�����Բ���д������Ż�������
 */

void ChatRoom::showMessage(User user, std::string message) {
	// C++ ��ȡ��ǰʱ��ο���<https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c>
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	char str[26];
	ctime_s(str, sizeof str, &end_time);
	// `ctime_s` �����������ɵ��ַ���ĩβ���һ�����з������ǿ���ʹ�� `std::string` �� `erase` �������Ƴ�����
	std::string time_str(str);
	time_str.erase(std::remove(time_str.begin(), time_str.end(), '\n'), time_str.end());
	std::cout << time_str << " [" << user.getName() << "] : " << message << std::endl;
}