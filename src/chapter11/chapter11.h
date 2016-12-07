#ifndef CPRIMER_CHAPTER11_CHAPTER11_H
#define CPRIMER_CHAPTER11_CHAPTER11_H

#include <typeinfo>
#include <iostream>
#include <cstring>

/**
* Template argument deduction.
* Const and volatile qualifiers are not dropped when matching reference parameters.
* Nonclass rvalue expressions never have const or volatile qualifiers.
*/
namespace chapter11 {

/**
* Test parameter by value.
*/
template<typename T>
void foo(T t) {
    std::cout << typeid(T).name() << std::endl;
}

template<typename T>
void bar(T &t) {
    std::cout << typeid(T).name() << std::endl;
}

// primary function template.
template<typename T>
inline T &max(T &lhs, T &rhs) {
    return lhs < rhs ? rhs : lhs;
}

// function overload.
inline const char *max(const char *lhs, const char *rhs) {
    return std::strcmp(lhs, rhs) < 0 ? rhs : lhs;
}

template<typename T> 
struct GetType {
public:
    typedef T type;
};

class S {
public:
    S() : m_ptr(0) {}

    // user-defined conversation to return array reference or function reference.
    template<typename T, int N>
    operator typename GetType<T (&)[N]>::type() {
        return *reinterpret_cast<T (*)[N]>(m_ptr);
    }

private:
    int *m_ptr;
};

// Test reference and value difference.
void chapter11_1_tutorial();

}

#endif
