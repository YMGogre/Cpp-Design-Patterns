#ifndef COMPUTERPART_H
#define COMPUTERPART_H

#include "ComputerPartVisitor.h"

/// <summary>
/// 表示元素的接口
/// </summary>
class ComputerPart
{

public:
	/// <summary>
	/// 纯虚接受函数
	/// </summary>
	/// <param name="computerPartVisitor">访问者对象的引用</param>
	virtual void accept(ComputerPartVisitor& computerPartVisitor) = 0;
	virtual ~ComputerPart() {}
};

#endif // !COMPUTERPART_H