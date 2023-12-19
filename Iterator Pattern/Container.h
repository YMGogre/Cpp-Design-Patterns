#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <memory>

template <typename T>
class Iterator;		// ʹ��ǰ�������Ա���ѭ������

/// <summary>
/// ��������
/// </summary>
/// <typeparam name="T">����Ԫ������</typeparam>
template <typename T>
class Container
{
protected:
	/// <summary>��ļ���</summary>
	std::vector<T> items;

public:
	Container(const std::vector<T>& init_vec) : items(init_vec) {}
	/// <summary>
	/// �����ȡ����������
	/// </summary>
	/// <returns>����������ָ��</returns>
	virtual std::unique_ptr<Iterator<T>> getIterator() = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Container() {}
	/// <summary>
	/// ��ȡ�����Ĵ�С
	/// </summary>
	/// <returns>����������ĸ���</returns>
	inline size_t size() const { return items.size(); }
	/// <summary>
	/// ���� [] �����
	/// </summary>
	/// <param name="index">�����±�</param>
	/// <returns>������ָ����������</returns>
	inline T& operator[](int index){ return items[index]; }
};

#endif // !CONTAINER_H