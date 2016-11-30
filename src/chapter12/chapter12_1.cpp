#include "chapter12/chapter12_1.h"

#include <sstream>

namespace chapter12_1 {

std::string Person::MailHeader() const {
    std::stringstream out;
    out << "Name: " << mName << std::endl
        << "Addr: " << mAddress << std::endl;
    return out.str();  
}

const Screen &Screen::Display(std::ostream &out) const {
    int start = 0;
    for (int i = 0; i < mHeight; ++i) {
        out << mContents.substr(start, mWidth) << std::endl;
        start += mWidth;
    }
    return *this;
}

void chapter12_2_tutorial() {
    Screen screen(10, 10);
    screen.MoveCursor(5, 5).set('*').Display(std::cout);
    screen.MoveCursor(9, 9).set('|').Display(std::cout);
}

}