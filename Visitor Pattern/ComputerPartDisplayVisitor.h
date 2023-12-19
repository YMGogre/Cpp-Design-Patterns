#ifndef COMPUTERPARTDISPLAYVISITOR_H
#define COMPUTERPARTDISPLAYVISITOR_H

#include "ComputerPartVisitor.h"
#include "Keyboard.h"
#include "Monitor.h"
#include "Mouse.h"
#include "Computer.h"
#include <iostream>

class ComputerPartDisplayVisitor :
	public ComputerPartVisitor
{

public:
	inline virtual void visit(Keyboard& keyboard) override {
		std::cout << "Displaying Keyboard." << std::endl;
	}
	inline virtual void visit(Monitor& monitor) override {
		std::cout << "Displaying Monitor." << std::endl;
	}
	inline virtual void visit(Mouse& mouse) override {
		std::cout << "Displaying Mouse." << std::endl;
	}
	inline virtual void visit(Computer& computer) override {
		std::cout << "Displaying Computer." << std::endl;
	}
};

#endif // !COMPUTERPARTDISPLAYVISITOR_H