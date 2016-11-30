#ifndef MAIN_CHAPTER12_CHAPTER12_H
#define MAIN_CHAPTER12_CHAPTER12_H

#include <string>
#include <iostream>

namespace chapter12 {

class SalesItem {
private:
	std::string mISBN;
	int 		mCount;
	double 		mRevenue;

public:
	explicit SalesItem(const std::string &isbn = "")
	: mISBN(isbn),
	  mCount(0),
	  mRevenue(0.0) {
	}

	SalesItem(const std::string &isbn, int count, double revenue)
	: mISBN(isbn),
	  mCount(count),
	  mRevenue(revenue) {
	}

	explicit SalesItem(std::istream &in);

	void UpdateCountAndRevenue(int count, double revenue) {
		mCount = count;
		mRevenue = revenue;
	}

	double Average() const;
};

}

#endif // MAIN_CHAPTER12_CHAPTER12_H
