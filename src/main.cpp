#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "src/stack.h"

int main(int argc, char **argv)
{
	Stack<int> intStack;
	Stack<std::string> textStack;

	intStack.push(10);
	intStack.pop();

	textStack.push("Hello world");
	textStack.pop();

	return EXIT_SUCCESS;
}