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
	/// <summary>����</summary>
	std::string name;
	/// <summary>����</summary>
	std::string dept;
	/// <summary>н��</summary>
	int salary;
	/// <summary>����</summary>
	std::vector<std::shared_ptr<Employee>> subordinates;
	/**
	 * subordinates ����洢����ָ�� Employee �����ָ�롣
	 * ��Ϊ std::vector::push_back() ��������ӵ�������ʱ���ᷢ���������졣
	 * ����ζ�� subordinates �洢���Ƕ���ĸ�����
	 * Ȼ���� vector �洢����ָ��ʱ���ȱ㷢���˿������죬�������ָ�븱��
	 * ��Ȼָ��ԭʼ����
	 */

public:
	/// <summary>
	/// ʵ���� Employee��ʹ��ָ�������֡����ź�н��
	/// </summary>
	/// <param name="_name">����</param>
	/// <param name="_dept">����</param>
	/// <param name="_salary">н��</param>
	inline Employee(std::string _name, std::string _dept, int _salary) :
		name(_name), dept(_dept), salary(_salary) {
	}
	/// <summary>
	/// ��ǰ Employee ������Ա���б������һ�� Employee
	/// </summary>
	/// <param name="e">����Ա�� Employee ����</param>
	inline void add(const std::shared_ptr<Employee> e) {
		subordinates.push_back(e);
	}
	/// <summary>
	/// �ӵ�ǰ Employee ������Ա���б����Ƴ�ָ���� Employee
	/// </summary>
	/// <param name="e">��Ҫ�Ƴ��� Employee</param>
	inline void remove(const std::shared_ptr<Employee> e) {
		auto item = std::find(subordinates.begin(), subordinates.end(), e);
		if (item != subordinates.end()) {
			subordinates.erase(item);
		}
	}
	/// <summary>
	/// ��ȡ��ǰԱ��������Ա���б�
	/// </summary>
	/// <returns>����Ա���б�</returns>
	inline std::vector<std::shared_ptr<Employee>> getSubordinates() {
		return subordinates;
	}
	// �������ص� << �����Ϊ��Ԫ�����Է���˽�г�Ա����
	friend std::ostream& operator<<(std::ostream& os, const Employee& obj);
};

/// <summary>
/// ���� << �����
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