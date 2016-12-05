#ifndef CPRIMER_CHAPTER5_TEMPLATE_CHAPTER5_H
#define CPRIMER_CHAPTER5_TEMPLATE_CHAPTER5_H

#include <iostream>
#include <bitset>

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

void template_chapter5_1_tutorial();

}

#endif