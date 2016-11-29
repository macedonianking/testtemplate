#include "chapter2/chapter2.h"

#include <string>
#include <iostream>

using std::istream;
using std::ostream;

void chapter2_3_problem() {
	std::string text = "C++ primer, 4th Ed.";
	std::cout << text << std::endl;
}

SalesItem2::SalesItem2(const std::string &isbn, int count, double revenue) 
: mISBN(isbn),
  mCount(count),
  mRevenue(revenue) {
}

SalesItem2 SalesItem2::operator+(const SalesItem2 &rhs) const {
	return SalesItem2(this->mISBN, this->mCount + rhs.mCount, this->mRevenue + rhs.mRevenue);
}

SalesItem2 &SalesItem2::operator=(const SalesItem2 &rhs) {
	if (this != &rhs) {
		mISBN = rhs.mISBN;
		mCount = rhs.mCount;
		mRevenue = rhs.mRevenue;
	}
	return *this;
}

bool SalesItem2::SameISBN(const SalesItem2 &rhs) const {
	return this->mISBN == rhs.mISBN;
}

double SalesItem2::Avenue() const {
	return mCount ? mRevenue / mCount : 0.0;
}

istream &operator>>(istream &in, SalesItem2 &rhs) {
	return in >> rhs.mISBN >> rhs.mCount >> rhs.mRevenue;
}

ostream &operator<<(ostream &out, const SalesItem2 &rhs) {
	return out << rhs.mISBN << " " << rhs.mCount << " " << rhs.mRevenue;
}

void chapter2_1_1_tutorial() {
	int a = 10, b = 20;
	std::cout << max(a, b) << std::endl;
	std::cout << max(static_cast<const int&>(a), b) << std::endl;
}
