#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>

class Employee
{

private:
	/// <summary>名字</summary>
	std::string name;
	/// <summary>部门</summary>
	std::string dept;
	/// <summary>薪资</summary>
	int salary;
	/// <summary>下属</summary>
	std::vector<std::shared_ptr<Employee>> subordinates;
	/**
	 * subordinates 必须存储的是指向 Employee 对象的指针。
	 * 因为 std::vector::push_back() 将对象添加到容器中时，会发生拷贝构造。
	 * 这意味着 subordinates 存储的是对象的副本。
	 * 然而当 vector 存储的是指针时，既便发生了拷贝构造，拷贝后的指针副本
	 * 仍然指向原始对象。
	 */

public:
	/// <summary>
	/// 实例化 Employee，使用指定的名字、部门和薪资
	/// </summary>
	/// <param name="_name">名字</param>
	/// <param name="_dept">部门</param>
	/// <param name="_salary">薪资</param>
	inline Employee(std::string _name, std::string _dept, int _salary) :
		name(_name), dept(_dept), salary(_salary) {
	}
	/// <summary>
	/// 向当前 Employee 的下属员工列表里添加一个 Employee
	/// </summary>
	/// <param name="e">下属员工 Employee 对象</param>
	inline void add(const std::shared_ptr<Employee> e) {
		subordinates.push_back(e);
	}
	/// <summary>
	/// 从当前 Employee 的下属员工列表里移除指定的 Employee
	/// </summary>
	/// <param name="e">将要移除的 Employee</param>
	inline void remove(const std::shared_ptr<Employee> e) {
		auto item = std::find(subordinates.begin(), subordinates.end(), e);
		if (item != subordinates.end()) {
			subordinates.erase(item);
		}
	}
	/// <summary>
	/// 获取当前员工的下属员工列表
	/// </summary>
	/// <returns>下属员工列表</returns>
	inline std::vector<std::shared_ptr<Employee>> getSubordinates() {
		return subordinates;
	}
	// 声明重载的 << 运算符为友元函数以访问私有成员变量
	friend std::ostream& operator<<(std::ostream& os, const Employee& obj);
};

/// <summary>
/// 重载 << 运算符
/// </summary>
/// <param name="os"></param>
/// <param name="obj"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const Employee& obj) {
	os << ("Employee : [ Name : " + obj.name
		+ ", dept : " + obj.dept + ", salary : "
		+ std::to_string(obj.salary) + " ]");
	return os;
}

#endif // !EMPLOYEE_H