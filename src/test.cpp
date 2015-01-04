#include "src/test.h"

#include "src/stack.h"

void doTest()
{
	Stack<int> intStack;
	Stack<std::string> textStack;

	intStack.push(10);
	intStack.pop();

	textStack.push("Hello world");
	textStack.pop();
}