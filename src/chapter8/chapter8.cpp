#include "chapter8/chapter8.h"

#include <iostream>
#include <vector>

namespace chapter8 {

void chapter8_2_tutorial() {
    std::cout << TestIterator<int>::value << std::endl;
    std::cout << TestIterator<std::vector<int>>::value << std::endl; 
}

}