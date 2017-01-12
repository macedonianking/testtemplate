#include <string>
#include <iostream>
#include <cstddef>

#include "wtf/Assertions.h"
#include "wtf/RefPtr.h"
#include "wtf/RawPtr.h"
#include <wtf/RefCounted.h>
#include "wtf/PassRefPtr.h"
#include "wtf/TypeTraits.h"
#include "Config.h"

using std::string;

namespace WTF {

class A {
public:
    void ref() {
    }

    void deref() {
    }
};

class B: public A {

};

void test(const RefPtr<B> &ptr);

void test() {
    RefPtr<B> ptr;
    test(ptr);
}

void test(const RefPtr<B> &ptr) {
    std::cout << ptr << std::endl;
}

void test_main() {
    ASSERT(1);
}

}
