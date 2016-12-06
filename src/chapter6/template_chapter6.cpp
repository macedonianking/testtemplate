#include "chapter6/template_chapter6.h"

namespace chapter6 {

void template_chapter6_1_tutorial() {
    double value = 3.0;
    print_typeinfo(value);
}

}

namespace chapter6_2 {

template<typename T>
void print_typeinfo(const T &t) {
    std::cout << typeid(T).name() << std::endl;
}

/**
* Explicit instanization function template for type double and int.
*/
template void print_typeinfo<double>(const double &t);
template void print_typeinfo<int>(const int &t);

}
