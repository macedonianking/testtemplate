#ifndef CPRIMER_CHAPTER12_CHAPTER12_1_H
#define CPRIMER_CHAPTER12_CHAPTER12_1_H

#include <stdlib.h>

#include <string>
#include <iostream>
#include <vector>

#include "macros.h"

#define INVALID_SCREEN_ID   -1

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

class WindowManager;

/*
 Specify how to use this pointer.
 return this reference for const and non const member function.
*/
class Screen {
public:
    // grant access to nonpublic members to class WindowManager.
    friend class WindowManager;

    Screen(int width, int height)
    : mScreenId(INVALID_SCREEN_ID),
      mContents(width * height, ' '),
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

    int id() const {
        return mScreenId;
    }
    void id(int screenId) {
        DCHECK(mScreenId == INVALID_SCREEN_ID && screenId != INVALID_SCREEN_ID);
        mScreenId = screenId;
    }

private:
    bool checkInternal(int x, int y) const {
        return 0 <= x && x < mWidth && 0 <= y && y < mHeight;
    }

private:
    int mScreenId;
    std::string mContents;
    int mWidth;
    int mHeight;
    int mCursorX;
    int mCursorY;
};

class WindowManager {
public:
    WindowManager() {}
    ~WindowManager();

    void AddScreen(Screen *screen);
    void RelocateScreen(int screenId, int cx, int cy) {
        Screen *screen = findScreen(screenId);
        if (screen != NULL) {
            screen->mCursorX = cx;
            screen->mCursorY = cy;
        }
    }

    Screen *findScreen(int screenId) const {
        Screen *screen = 0;
        for (std::vector<Screen*>::const_iterator iter = mScreenVector.begin();
             iter != mScreenVector.end();
             iter++) {
            if ((*iter)->id() == screenId) {
                screen = *iter;
                break;
            }
        }
        return screen;
    }

private:
    static int nextIdInternal();
    static int sNextScreenId;

private:
    std::vector<Screen*> mScreenVector;
};

void chapter12_2_tutorial();

}

#endif // CPRIMER_CHAPTER12_CHAPTER12_1_H