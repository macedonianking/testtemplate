#ifndef MAIN_SRC_STACH_H
#define MAIN_SRC_STACH_H

#include <vector>
#include <string>
#include <stdexcept>

template<typename T, typename TContainer = std::vector<T>>
class Stack
{
public:
	Stack()
	{

	}
	Stack(const Stack<T, TContainer> &item)
	{
		this->mElements = item.mElements;
	}

	~Stack()
	{

	}

	Stack<T> &operator=(const Stack<T, TContainer> &rhs)
	{
		if (this != &rhs) {
			this->mElements = rhs.mElements;
		}
		return *this;
	}

	template<typename U, typename UContainer>
	Stack<T, TContainer> &operator=(const Stack<U, UContainer> &rhs)
	{
		if ((void*)this == (void*)&rhs)
		{
			return *this;
		}

		Stack<U, UContainer> tmp(rhs);
		this->mElements.clear();
		while (!tmp.empty())
		{
			mElements.push_front(tmp.top());
			tmp.pop();
		}

		return *this;
	}

	void push(const T &item)
	{
		mElements.push_back(item);
	}

	void pop();

	bool empty() const
	{
		return mElements.empty();
	}

	T &top()
	{
		if (mElements.empty())
		{
			throw std::out_of_range("Stack<T>::top()");
		}
		return mElements.back();
	}

	const T &top() const
	{
		if (mElements.empty())
		{
			throw std::out_of_range("Stack<T>::top()");
		}
		return mElements.back();
	}

private:
	TContainer mElements;
};

template<typename T, typename TContainer>
void Stack<T, TContainer>::pop()
{
	if (mElements.empty())
	{
		throw std::out_of_range("Stack<T>::pop()");
	}
	mElements.pop_back();
}

template<>
class Stack<std::string>
{
public:
	Stack()
	{

	}

	~Stack()
	{

	}

	void push(const std::string &item)
	{
		mElements.push_back(item);
	}

	void pop();

	bool empty() const
	{
		return mElements.empty();
	}

	std::string &top()
	{
		if (mElements.empty())
		{
			throw std::out_of_range("Stack<T>::top()");
		}
		return mElements.back();
	}

	const std::string &top() const
	{
		if (mElements.empty())
		{
			throw std::out_of_range("Stack<T>::top()");
		}
		return mElements.back();
	}
private:
	std::vector<std::string> mElements;
};

#endif // MAIN_SRC_STACH_H