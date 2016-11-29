#include "chapter12/chapter12.h"

SalesItem12::SalesItem12()
: mCount(0),
  mRevenue(0) {
}

SalesItem12::SalesItem12(const std::string &isbn, int count, double revenue)
: mISBN(isbn),
  mCount(count),
  mRevenue(revenue) 
{
}

SalesItem12::SalesItem12(const char *isbn, int count, double revenue)
: mISBN(isbn),
  mCount(count),
  mRevenue(revenue) 
{
}

void SalesItem12::Dump(std::ostream &out) const {
	out << "void SalesItem12::Dump(std::ostream &) const";
}

void SalesItem12::Dump(std::ostream &out) {
	out << "void SalesItem12::Dump(std::ostream &)";
}

SalesItem12 &SalesItem12::operator=(const SalesItem12& rhs) {
    if (&rhs != this) {
        mISBN = rhs.mISBN;
        mCount = rhs.mCount;
        mRevenue = rhs.mRevenue;
    } 
    return *this;
}

Person::Person() {
}

Person::Person(const char *name, const char *address)
: mName(name),
  mAddress(address) {
}

void chapter12_1_tutorial() {
	SalesItem12 item("KKKFR", 10, 200303.0);
	((const SalesItem12&)item).Dump(std::cout);
	std::cout << std::endl;
}

Screen::Screen(int width, int height)
: mWidth(width),
  mHeight(height),
  mContents(width * height, ' ') {
    this->AdjustCursor();
}

void Screen::AdjustCursor() {
    if (mCursorX >= mWidth) {
        mCursorX = mWidth - 1;
    } else if(mCursorX < 0) {
        mCursorX = 0;
    }
    if (mCursorY >= mHeight) {
        mCursorY = mHeight - 1;
    } else if(mCursorY < 0) {
        mCursorY = 0;
    }
}

Screen::Screen(const Screen &rhs)
: mWidth(rhs.mWidth),
  mHeight(rhs.mHeight),
  mCursorX(rhs.mCursorX),
  mCursorY(rhs.mCursorY),
  mContents(rhs.mContents) {
}

void WindowManager::RelocateScreen(int offsetCursorX, int offsetCursorY) {
    mScreen->mCursorX += offsetCursorX;
    mScreen->mCursorY += offsetCursorY;
    mScreen->AdjustCursor();
}
