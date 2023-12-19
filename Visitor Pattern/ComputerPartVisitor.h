#ifndef COMPUTERPARTVISITOR_H
#define COMPUTERPARTVISITOR_H

// ʹ��ǰ�������Ա���ѭ������
class Keyboard;
class Monitor;
class Mouse;
class Computer;

/// <summary>
/// ��ʾ�����ߵĽӿ�
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