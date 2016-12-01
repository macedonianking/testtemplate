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

WindowManager::~WindowManager() {
    for (std::vector<Screen*>::iterator iter = mScreenVector.begin();
         iter != mScreenVector.end();
         ++iter) {
        delete *iter;
    }
    mScreenVector.clear();
}

void WindowManager::AddScreen(Screen *screen) {
    Screen *tmp;

    if (screen->id() == INVALID_SCREEN_ID) {
        screen->id(nextIdInternal());
    }
    tmp = findScreen(screen->id());
    if (tmp == NULL) {
        mScreenVector.push_back(screen);
    }
}

int WindowManager::sNextScreenId = 0;

int WindowManager::nextIdInternal() {
    return sNextScreenId++;
}

void chapter12_2_tutorial() {
    Screen screen(10, 10);
    screen.MoveCursor(5, 5).set('*').Display(std::cout);
    screen.MoveCursor(9, 9).set('|').Display(std::cout);
}

}