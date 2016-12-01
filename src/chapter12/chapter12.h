#ifndef MAIN_CHAPTER12_CHAPTER12_H
#define MAIN_CHAPTER12_CHAPTER12_H

#include <string>
#include <iostream>

namespace chapter12 {

class SalesItem;
std::ostream &operator<<(std::ostream &, const SalesItem &);
std::istream &operator>>(std::istream &, SalesItem &);

class SalesItem {

public:
	// Suppressing implicit conversations defined by construtor.
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

	// Suppress implicit conversations defined by constructor.
	explicit SalesItem(std::istream &in);

	void UpdateCountAndRevenue(int count, double revenue) {
		mCount = count;
		mRevenue = revenue;
	}

	bool SameISBN(const SalesItem &item) const;
	double Average() const;

	friend std::ostream &operator<<(std::ostream &out, const SalesItem &item);
	friend std::istream &operator>>(std::istream &out, SalesItem &item);

private:
	std::string mISBN;
	int 		mCount;
	double 		mRevenue;
};

}

#endif // MAIN_CHAPTER12_CHAPTER12_H
