#ifndef CPRIMER_CHAPTER6_TEMPLATE_CHAPTER6_H
#define CPRIMER_CHAPTER6_TEMPLATE_CHAPTER6_H

#include <typeinfo>
#include <iostream>

namespace chapter6 {

template<typename T>
void print_typeinfo(const T &t) {
    std::cout << typeid(t).name() << std::endl;
}

void template_chapter6_1_tutorial();

}

namespace chapter6_2 {

template<typename T>
void print_typeinfo(const T &t);

}

namespace chapter6_3 {



}

#endif // CPRIMER_CHAPTER6_TEMPLATE_CHAPTER6_H