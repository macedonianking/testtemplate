#include "chapter15/template_chapter15.h"

#include <iostream>

#include "util.h"

namespace template_chapter15 {


void chapter15_1_tutorial() {
    int data_buf[] = {1, 2, 3, 4, 5};
    char name[] = "Helloworld";
    std::cout << accumulate(data_buf, data_buf + NARRAY(data_buf)) << std::endl;
    std::cout << accumulate(name, name + NARRAY(name) - 1) << std::endl;
    std::cout << Accumulate<int, MultiPolicy>::accumulate(data_buf, data_buf + NARRAY(data_buf))
              << std::endl;
}


}
