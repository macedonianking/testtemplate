#include "chapter12/chapter12_4.h"

#include <string>

namespace chapter12_4 {

void chapter12_4_tutorial() {
    List<std::string*> stringList;
    List<void*> voidPtrList;
    std::cout << stringList.length() << std::endl;
    std::cout << voidPtrList.length() << std::endl;
}

}