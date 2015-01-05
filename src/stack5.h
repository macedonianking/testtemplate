#ifndef MAIN_SRC_STACK5_H_
#define MAIN_SRC_STACK5_H_

#include <vector>
#include <stdexcept>

template<typename T, 
	template<typename Tp, 
			typename Alloc = std::allocator<Tp>> 
			class TConatiner = std::vector>
class Stack5
{
public:
	Stack5()
	{
	}

	Stack5(const Stack5<T, TConatiner> &rhs) :
		mElements(rhs.mElements)
	{
	}

	template<typename U, 
			template<typename Up, typename UpAlloc=std::allocator<Up>> class UpContainer>
	Stack5(const Stack5<U, UpContainer> &rhs);

	~Stack5()
	{
	}

	Stack5<T, TConatiner> &operator=(const Stack5<T, TConatiner> &rhs)
	{
		if (this != &rhs) {
			this->mElements = rhs.mElements;
		}
		return *this;
	}

	template<typename U, 
			template<typename, typename> class UpContainer>
	Stack5<T, TConatiner> &operator=(const Stack5<U, UpContainer> &rhs);

	void push(const T &rhs)
	{
		mElements.push_back(rhs);
	}

	void pop()
	{
		if (mElements.empty())
		{
			throw std::out_of_range("Stack5<T, TConatiner>::pop");
		}
		mElements.pop_back();
	}

	bool empty() const
	{
		return mElements.empty();
	}

	T &top()
	{
		if (mElements.empty())
		{
			throw std::out_of_range("Stack5<T, TConatiner>::top");
		}
		return mElements.back();
	}
private:
	TConatiner<T> 	mElements;
};

template<typename T, 
		template<typename, typename> class TpContainer>
template<typename U,
		template<typename, typename> class UpContainer>
Stack5<T, TpContainer>::Stack5(const Stack5<U, UpContainer> &rhs)
{
	Stack5<U, UpContainer> tmp(rhs);
	while (!tmp.empty()) {
		mElements.push_front(tmp.top());
		tmp.pop();
	}
}

template<typename T, 
		template<typename, typename> class TpContainer>
template<typename U, 
		template<typename, typename> class UpContainer>
Stack5<T, TpContainer> &Stack5<T, TpContainer>::operator=(const Stack5<U, UpContainer> &rhs)
{
	if ((void*) this == (void*)&rhs)
	{
		return *this;
	}

	Stack5<U, UpContainer> tmp(rhs);
	while (!tmp.empty()) {
		mElements.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}

#endif // MAIN_SRC_STACK5_H_