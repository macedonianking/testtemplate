#include "chapter15/template_chapter15_3.h"

#include <string>
#include <iostream>

namespace template_chapter15_3 {

void template_chapter15_3_tutorial() {
    std::cout << IsClassConstructableFrom<std::string, const char *>::value << std::endl;
}

}