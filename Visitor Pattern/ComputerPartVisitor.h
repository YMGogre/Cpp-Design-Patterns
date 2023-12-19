#ifndef COMPUTERPARTVISITOR_H
#define COMPUTERPARTVISITOR_H

// 使用前向声明以避免循环依赖
class Keyboard;
class Monitor;
class Mouse;
class Computer;

/// <summary>
/// 表示访问者的接口
/// </summary>
class ComputerPartVisitor
{

public:
	virtual void visit(Keyboard& keyboard) = 0;
	virtual void visit(Monitor& monitor) = 0;
	virtual void visit(Mouse& mouse) = 0;
	virtual void visit(Computer& computer) = 0;
	virtual ~ComputerPartVisitor() {}
};

#endif // !COMPUTERPARTVISITOR_H