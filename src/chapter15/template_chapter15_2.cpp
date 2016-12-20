#include "chapter15/template_chapter15_2.h"

#include <iostream>
#include <typeinfo>
#include <vector>

namespace template_chapter15_2 {

// 不能从第一个参数推出T的类型
template<typename T>
static inline void apply(typename RemoveReference<T>::reference t, void (*func)(T)) {
    func(t);
}

template<typename T>
void print_type_info(const T &ref) {
    std::cout << typeid(typename ContainerType<T>::value_type).name() << std::endl;
}

void template_chapter15_2_tutorial() {
    std::vector<int> nStack;
    std::cout << TypeSize<int>::value << std::endl;
    print_type_info(nStack);
}

}
