#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include <deque>
#include <iostream>
#include <string>
#include <map>

#include <typeinfo>

#include "src/stack.h"
#include "src/test.h"



int main(int argc, char **argv)
{

	doTest();
	return EXIT_SUCCESS;
}

void doMainTest()
{
	Stack<int> intStack;
	Stack<float, std::deque<float>> floatStack;

	intStack.push(10);
	intStack.pop();

	floatStack = intStack;
}