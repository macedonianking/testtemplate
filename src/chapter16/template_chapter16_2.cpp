#include "chapter16/template_chapter16_2.h"

#include <iostream>

namespace template_chapter16_2 {

class EmptyOne {
};

class EmptyTwo: public EmptyOne {
};

class EmptyThree : public EmptyTwo, public EmptyOne {

};

void chapter16_2_tutorial() {
    std::cout << sizeof(EmptyThree) << std::endl;
}

}