#include "Computer.h"
#include "ComputerPart.h"
#include "ComputerPartDisplayVisitor.h"

int main() {
	ComputerPart* computer = new Computer();
	ComputerPartDisplayVisitor visitor;
	computer->accept(visitor);
	delete computer;
}