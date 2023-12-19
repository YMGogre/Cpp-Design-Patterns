#include "Expression.h"
#include "TerminalExpression.h"
#include "AndExpression.h"
#include "OrExpression.h"
#include <memory>
#include <iostream>

// 规则：Robert 和 John 是男性
static std::shared_ptr<Expression> getMaleExpression() {
	std::shared_ptr<Expression> robert = std::make_shared<TerminalExpression>("Robert");
	std::shared_ptr<Expression> john = std::make_shared<TerminalExpression>("John");
	return std::make_shared<OrExpression>(robert, john);
}

// 规则：Julie 是一位已婚的女性
static std::shared_ptr<Expression> getMarriedWomanExpression() {
	std::shared_ptr<Expression> julie = std::make_shared<TerminalExpression>("Julie");
	std::shared_ptr<Expression> married = std::make_shared<TerminalExpression>("Married");
	return std::make_shared<AndExpression>(julie, married);
}

int main() {
	std::shared_ptr<Expression> isMale = getMaleExpression();
	std::shared_ptr<Expression> isMarriedWoman = getMarriedWomanExpression();

	std::cout << "John is male? " << std::boolalpha << isMale->interpret("John") << std::endl;
	std::cout << "Julie is a married women? " << std::boolalpha << isMarriedWoman->interpret("Married Julie") << std::endl;
}