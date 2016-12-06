#ifndef CPRIMER_CHAPTER5_TEMPLATE_CHAPTER6_H
#define CPRIMER_CHAPTER5_TEMPLATE_CHAPTER6_H

#include <typeinfo>
#include <iostream>

namespace chapter6 {

template<typename T>
void print_typeinfo(const T &t) {
    std::cout << typeid(t).name() << std::endl;
}

void template_chapter6_1_tutorial();

}

#endif // CPRIMER_CHAPTER5_TEMPLATE_CHAPTER6_H