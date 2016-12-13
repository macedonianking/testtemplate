#include "chapter12/template_chapter12.h"

#include <iostream>
#include <vector>
#include <deque>

namespace chapter12 {

void chapter12_1_tutorial() {
}

template<typename T>
void bar(const T &) {
    std::cout << "template function" << std::endl;
}

void bar(int &) {
    std::cout << "non template function" << std::endl;
}

void chapter12_1_2_tutorial() {
    int a = 10;
    int b = 20;
    swap(&a, &b);
    bar(a);
}

}

namespace chapter12_3 {

void chapter12_3_tutorial() {
    S<bool>().msg();
    S<void>().msg();
}

}