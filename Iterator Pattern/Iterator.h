#ifndef ITERATOR_H
#define ITERATOR_H

#include "Container.h"

/// <summary>
/// ���������
/// </summary>
/// <typeparam name="T">���������������</typeparam>
template <typename T>
class Iterator
{
protected:
	/// <summary>�������������</summary>
	Container<T>& container;
	/// <summary>�������</summary>
	size_t index = 0;

public:
	Iterator(Container<T>& _container) : container(_container) {}
	/// <summary>
	/// ����ӵ����һ���
	/// </summary>
	/// <returns>���� true �������һ����򷵻� false</returns>
	virtual bool hasNext() = 0;
	/// <summary>
	/// �����ȡ��һ���
	/// </summary>
	/// <returns>�����е���һ��</returns>
	virtual T next() = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Iterator() {}
};

#endif // !ITERATOR_H