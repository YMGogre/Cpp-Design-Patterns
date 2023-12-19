#ifndef PERSON_H
#define PERSON_H

#include <string>

/// <summary>
/// ����һ�� Person �࣬���ǽ��ڸ�����Ӧ�ù���������׼��
/// </summary>
class Person
{

private:
	/// <summary>����</summary>
	std::string name;
	/// <summary>�Ա�</summary>
	std::string gender;
	/// <summary>����״��</summary>
	std::string maritalStatus;

public:
	inline Person(std::string _name, std::string _gender, std::string _maritalStatus) :
		name(_name), gender(_gender), maritalStatus(_maritalStatus) {
	}
	/// <summary>
	/// ���� == �������OrCriteria ����ʹ���� std::find ���������� == ���������Ƚ�Ԫ�أ�
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
	/// ��ȡ����
	/// </summary>
	/// <returns>����</returns>
	inline std::string getName() {
		return name;
	}
	/// <summary>
	/// ��ȡ�Ա�
	/// </summary>
	/// <returns>�Ա�</returns>
	inline std::string getGender() {
		return gender;
	}
	/// <summary>
	/// ��ȡ����״��
	/// </summary>
	/// <returns>����״��</returns>
	inline std::string getMaritalStatus() {
		return maritalStatus;
	}
};

#endif // !PERSON_H