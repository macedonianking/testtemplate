#ifndef CPRIMER_CHAPTER12_CHAPTER12_1_H
#define CPRIMER_CHAPTER12_CHAPTER12_1_H

#include <string>
#include <iostream>

#include "macros.h"

namespace chapter12_1 {

class Person {
public:
    Person(const std::string &name, std::string &address) 
    : mName(name), mAddress(address) {
    }

    const std::string &name() const {
        return mName;
    }

    const std::string &address() const {
        return mAddress;
    }

    void name(const std::string &name) {
        mName = name;
    }

    void address(const std::string &address) {
        mAddress = address;
    }

    /**
     * 写邮件的开头
     */
    std::string MailHeader() const;

private:
    std::string mName;
    std::string mAddress;
};

/*
 Specify how to use this pointer.
 return this reference for const and non const member function.
*/
class Screen {
public:
    Screen(int width, int height)
    : mContents(width * height, ' '),
      mWidth(width),
      mHeight(height)
    {
    }

    Screen &MoveCursor(int cursorX, int cursorY) {
        cursorX = cursorX < 0 ? 0 : (cursorX >= mWidth ? mWidth - 1 : cursorX);
        cursorY = cursorY < 0 ? 0 : (cursorY >= mHeight ? mHeight - 1 : cursorY);
        mCursorX = cursorX;
        mCursorY = cursorY;
        return *this;
    }

    int width() const { return mWidth; }
    int height() const { return mHeight; }
    int CursorX() const { return mCursorX; }
    int CursorY() const { return mCursorY; }

    char get(int x, int y) const {
        DCHECK(checkInternal(x, y));
        return mContents[mWidth * y + x];
    }

    char get() const {
        return get(mCursorX, mCursorX);
    }

    Screen &set(int x, int y, char ch) {
        DCHECK(checkInternal(x, y));
        mContents[y * mWidth + x] = ch;
        return *this;
    }

    Screen &set(char ch) {
        return set(mCursorX, mCursorY, ch);
    }

    const Screen &Display(std::ostream &out) const;

    Screen &Display(std::ostream &out) {
        static_cast<const Screen*>(this)->Display(out);
        return *this;
    }

private:
    bool checkInternal(int x, int y) const {
        return 0 <= x && x < mWidth && 0 <= y && y < mHeight;
    }

private:
    std::string mContents;
    int mWidth;
    int mHeight;
    int mCursorX;
    int mCursorY;
};

void chapter12_2_tutorial();

}

#endif // CPRIMER_CHAPTER12_CHAPTER12_1_H