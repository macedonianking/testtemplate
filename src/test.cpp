#include "src/test.h"

#include <typeinfo>
#include <deque>

#include "src/stack.h"
#include "src/stack4.h"
#include "src/stack5.h"

template<typename Tp>
void testRef(const Tp &ref)
{
	std::cout << "testRef:" << typeid(Tp).name() << std::endl;
}

template<typename Tp>
void testValue(Tp value)
{
	std::cout << "testValue:" << typeid(Tp).name() << std::endl;
}

static inline void testDifferenceBetweenRefAndValue()
{
	testRef("Hello");
	testValue("Hello");
}

void doTest()
{
	Stack<int> intStack;
	Stack<std::string> textStack;
	Stack4<int, 100> int100Stack;
	Stack5<int> intStack5;

	intStack.push(10);
	intStack.pop();

	textStack.push("Hello world");
	textStack.pop();

	int100Stack.push(10);
	int100Stack.pop();

	intStack5.push(100);
	intStack5.pop();

	Stack5<int, std::vector> stack5Int1;
	stack5Int1.push(1);
	stack5Int1.push(2);

	Stack5<float, std::deque> stack5Float1(stack5Int1);

	testDifferenceBetweenRefAndValue();
}