#include "chapter11/chapter11.h"

namespace chapter11 {

void chapter11_1_tutorial() {
    const int data[10] = {1, 2};
    foo(data);
    bar(data);
    foo(7); // nonclass rvalue expression never have const or volatile qualifier. 7->int
    // foo<int>
    // bar(7); // fail, bar<int>(int &) do not match int
    void (*ptr)(std::string *) = &foo;
    std::cout << ptr << std::endl;
}

}