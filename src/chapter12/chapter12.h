#ifndef MAIN_CHAPTER12_CHAPTER12_H
#define MAIN_CHAPTER12_CHAPTER12_H

#include <string>
#include <iostream>

class SalesItem12 {
public:
	SalesItem12();
	SalesItem12(const char *isbn, int count, double revenue);
	SalesItem12(const std::string &isbn, int count, double revenue);

	inline double Average() const {
		if (!mCount) {
			return 0.0;
		} else {
			return mRevenue / mCount;
		}
	}

	void Dump(std::ostream &out);
	void Dump(std::ostream &out) const;

	SalesItem12 &operator=(const SalesItem12 &rhs);

private:
	std::string		mISBN;
	int 			mCount;
	double			mRevenue;
};

class Person {
public:
	Person();
	Person(const char *name, const char *person);

	const std::string &Name() const {return mName;}
	const std::string &Address() const {return mAddress;}

private:
	std::string 	mName;
	std::string		mAddress;
};

class Screen {
public:
	Screen(int width, int height);
	Screen(const Screen &rhs);

	char Get() const {
		return mContents[mCursorY * mWidth + mCursorY];
	}

	Screen &Move(int x, int y) {
		mCursorX = x;
		mCursorY = y;
		this->AdjustCursor();
		return *this;
	}

private:
	void AdjustCursor();

	friend class WindowManager;
private:
	int 		mWidth;
	int 		mHeight;
	int 		mCursorX, mCursorY;
	std::string mContents;
};

class WindowManager {
public:
	explicit WindowManager(Screen *screen) :
	  mScreen(screen) {
	}

private:
	void RelocateScreen(int offsetCursorX, int offsetCursorY);

private:
	Screen *mScreen;
};

void chapter12_1_tutorial();

#endif // MAIN_CHAPTER12_CHAPTER12_H
