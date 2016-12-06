#include <string>
#include <iostream>
#include <cstddef>

#include "wtf/RefPtr.h"
#include "wtf/RawPtr.h"
#include "Config.h"

using std::string;

namespace WTF {

void test() {
    RawPtr<string> rawPtr(nullptr);
    std::cout << rawPtr.get() << std::endl;
}

}