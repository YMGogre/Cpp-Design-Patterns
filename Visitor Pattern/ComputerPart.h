#ifndef COMPUTERPART_H
#define COMPUTERPART_H

#include "ComputerPartVisitor.h"

/// <summary>
/// ��ʾԪ�صĽӿ�
/// </summary>
class ComputerPart
{

public:
	/// <summary>
	/// ������ܺ���
	/// </summary>
	/// <param name="computerPartVisitor">�����߶��������</param>
	virtual void accept(ComputerPartVisitor& computerPartVisitor) = 0;
	virtual ~ComputerPart() {}
};

#endif // !COMPUTERPART_H