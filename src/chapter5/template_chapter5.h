#ifndef CPRIMER_CHAPTER5_TEMPLATE_CHAPTER5_H
#define CPRIMER_CHAPTER5_TEMPLATE_CHAPTER5_H

#include <iostream>
#include <bitset>
#include <vector>
#include <deque>

namespace chapter5 {

template<typename T>
class MyClass {
public:
    /**
     * Specify that an identifier inside a template is type.
     */
    typename T::SubType *ptr;

};

/**
 * typename is used to specify that a identifier inside a template is a type.
 */
template<typename T>
inline void print_collection(const T &t) {
    typename T::const_iterator iter;
    typename T::const_iterator end;

    end = t.end();
    for (iter = t.begin(); iter != end; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

/**
 * t depends on template parametes, and to string depends on t.
 * Specify that to_string is template function.
 */
template<long long unsigned N>
inline void print_bitset(const std::bitset<N> &t) {
    std::cout << t.template to_string<char, std::char_traits<char>, std::allocator<char>>()
        << std::endl;
}

template<typename T>
class Stack {
public:
    Stack() {}

    T &Top() { return mDataList.back(); }
    void Pop() { 
        mDataList.pop_back(); 
    }

    void Push(const T &t) {
        mDataList.push_back(t);
    }
    bool IsEmpty() const {
        return mDataList.empty();
    }

    template<typename U>
    Stack<T> &operator=(const Stack<U> &t);

private:
    std::vector<T> mDataList;
};

template<typename T>
template<typename U>
Stack<T> &Stack<T>::operator=(const Stack<U> &t) {
    if ((void*)this == (void*)&t) {
        return *this;
    }

    Stack<U> temp(t);
    mDataList.clear();
    while (!temp.IsEmpty()) {
        mDataList.insert(mDataList.begin(), temp.Top());
        temp.Pop();
    }
    return *this;
}

/**
 * Specify where to use .template keyword.
 */
void template_chapter5_1_tutorial();
void template_chapter5_3_tutorial();

}

/**
 * Specify template template parameters.<br/>
 * 示范如何使用template template parameter.<br/>
 * 参数的个数必须完全相同
 */
namespace chapter5_4 {

template<typename T, 
    template<typename _T = T, typename = std::allocator<_T>> class Container = std::deque>
class Stack {
public:
    Stack() {}
    
    bool IsEmpty() const { return mDataList.empty(); }
    T &Top() { return mDataList.back(); }
    void Pop() {
        mDataList.pop_back();
    }
    void Push(const T &t) {
        mDataList.push_back(t);
    }

    template<typename U, template<typename, typename> class UContainer>
    Stack<T, Container> &operator=(const Stack<U, UContainer> &t);

private:
    Container<T> mDataList;
};

template<typename T, template<typename, typename> class Container>
template<typename U, template<typename, typename> class UContainer>
Stack<T, Container> &Stack<T, Container>::operator=(const Stack<U, UContainer> &t) {
    if (static_cast<void*>(this) == static_cast<void*>(&t)) {
        return *this;
    }
    Stack<U, UContainer> temp(t);
    mDataList.clear();
    while (temp.IsEmpty()) {
        mDataList.insert(mDataList.begin(), temp.Top());
        temp.Pop();
    }
    return *this;
}

void template_chapter5_4_tutorial();
}

// zero initialization.
// T x = T() for function
// x() for constructor initializer.

// string literal use in template.
// string char [6]
#endif