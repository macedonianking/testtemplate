#ifndef CPRIMER_CHAPTER12_TEMPLATE_CHAPTER12_H
#define CPRIMER_CHAPTER12_TEMPLATE_CHAPTER12_H

/**
Specilization and overloading.
* Why one funtion template participate in overset of 
* anbiguity error.
* Partial ordering rule
* Full specialization.
*/
#include <stdlib.h>
#include <iostream>

#include "macros.h"


namespace chapter12 {

template<typename T>
class Array {
public:
    Array(int length) 
    : _M_ptr(new T[length]),
      _M_size(length)
    {
    }

    ~Array() {
        if (_M_ptr)
            delete _M_ptr;
        _M_ptr = NULL;
    }

    void swap(Array<T> &rhs) {
        T *ptr = _M_ptr;
        int size = _M_size;
        _M_ptr = rhs._M_ptr;
        _M_size = rhs._M_size;
        rhs._M_ptr = ptr;
        rhs._M_size = size;
    }

    T &operator[](int i) {
        return _M_ptr[i];
    }

private:
    DISALLOW_COPY_AND_ASSIGN(Array);

private:
    T   *_M_ptr;
    int _M_size;
};

template<typename T>
inline void swap(T *lhs, T *rhs) {
    T temp(*lhs);
    *lhs = *rhs;
    *rhs = temp;
}

// This template is more specialized than the first one.
template<typename T>
inline void swap(Array<T> *lhs, Array<T> *rhs) {
    lhs->swap(*rhs);
}

template<>
inline void swap(Array<int> *lhs, Array<int> *rhs) {
    lhs->swap(*rhs);
}

// primary template
template<typename T>
inline int foo(T t) {
    return 1; 
}

// Specialized template.
template<typename T>
inline int foo(T *t) {
    return 2;
}

// f<int*> has two overload function and will be selected by argument types.
void chapter12_1_tutorial();
void chapter12_1_2_tutorial();
}

// Full class template specialization 
namespace chapter12_3 {

// generic template definition
template<typename T>
class S {
public:
    void msg() const {
        std::cout << "S::msg template" << std::endl;
    }
};

// full class template definition
// The list of specified template arguments must correspond to the list of template parameters.
// It is not a class template, just syntax is a litte different than normal class template.
template<>
class S<void> {
public:
    void msg() const {
        std::cout << "S::msg full class template specialization" << std::endl;
    }
};

void chapter12_3_tutorial();

}

#endif