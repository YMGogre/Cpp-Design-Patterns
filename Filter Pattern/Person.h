#ifndef PERSON_H
#define PERSON_H

#include <string>

/// <summary>
/// 创建一个 Person 类，我们将在该类上应用过滤器（标准）
/// </summary>
class Person
{

private:
	/// <summary>名字</summary>
	std::string name;
	/// <summary>性别</summary>
	std::string gender;
	/// <summary>婚姻状况</summary>
	std::string maritalStatus;

public:
	inline Person(std::string _name, std::string _gender, std::string _maritalStatus) :
		name(_name), gender(_gender), maritalStatus(_maritalStatus) {
	}
	/// <summary>
	/// 重载 == 运算符（OrCriteria 类中使用了 std::find 函数依赖于 == 操作符来比较元素）
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline bool operator==(const Person& other) const {
		if (this->name == other.name && this->gender == other.gender && this->maritalStatus == other.maritalStatus) {
			return true;
		}
		return false;
	}
	/// <summary>
	/// 获取名字
	/// </summary>
	/// <returns>名字</returns>
	inline std::string getName() {
		return name;
	}
	/// <summary>
	/// 获取性别
	/// </summary>
	/// <returns>性别</returns>
	inline std::string getGender() {
		return gender;
	}
	/// <summary>
	/// 获取婚姻状况
	/// </summary>
	/// <returns>婚姻状况</returns>
	inline std::string getMaritalStatus() {
		return maritalStatus;
	}
};

#endif // !PERSON_H