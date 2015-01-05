#ifndef MAIN_SRC_STACK4_H_
#define MAIN_SRC_STACK4_H_

#include <stddef.h>
#include <stdexcept>

template<typename T, int MAXSIZE = 128>
class Stack4{
public:
	Stack4() :
		mSize(0)
	{

	}

	~Stack4()
	{

	}

	void push(const T &item)
	{
		if (mSize >= MAXSIZE)
		{
			throw std::out_of_range("Stack4<T, MAXSIZE>::push");
		}
		mElements[mSize++] = item;
	}

	void pop()
	{
		if (mSize <= 0)
		{
			throw std::out_of_range("Stack4<T, MAXSIZE>::pop");
		}
		--mSize;
	}

	bool empty() const
	{
		return mSize <= 0;
	}

	T &top()
	{
		if (mSize <= 0)
		{
			throw std::out_of_range("Stack4<T, MAXSIZE>::top");
		}
		return mElements[mSize - 1];
	}
private:
	T 		mElements[MAXSIZE];
	size_t	mSize;
};

#endif // MAIN_SRC_STACK4_H_