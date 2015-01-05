#ifndef MAIN_SRC_TEST_H_
#define MAIN_SRC_TEST_H_

#include <iostream>

void doTest();

template<typename T>
void print(const T &values)
{
	typename T::const_iterator iter;
	typename T::const_iterator end;

	end = values.end();
	iter = values.begin();
	while (iter != end)
	{
		std::cout << *iter << ' ';
		++iter;
	}
	std::cout << std::endl;
}

#endif // MAIN_SRC_TEST_H_