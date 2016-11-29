#ifndef MAIN_CHAPTER1_CHAPTER1_H
#define MAIN_CHAPTER1_CHAPTER1_H

#include <string>
#include <iostream>

void chapter1_read_SalesItem();
void chapter1_2_2_problem();
void chapter1_24problem();
void chapter1_6_tutorial();

class SalesItem {
public:
	SalesItem() {
	}

	bool SameISBN(const SalesItem &rhs) {
		return this->mISBN == rhs.mISBN;
	}

	const std::string &ISBN() const {
		return mISBN;
	}

	double Avenue() const {
		return mRevenue / mCount;
	}

	void AddAvenue(int count, double revenue);

	SalesItem operator+(const SalesItem &rhs) const;
	SalesItem &operator+=(const SalesItem &rhs);

	friend std::istream &operator>>(std::istream &in, SalesItem &item);
	friend std::ostream &operator<<(std::ostream &out, const SalesItem &item);
private:
	std::string mISBN;
	double 		mRevenue;
	int 		mCount;
};

std::istream& operator>>(std::istream &in, SalesItem &item);
std::ostream& operator<<(std::ostream &out, const SalesItem &item);

#endif // MAIN_CHAPTER1_CHAPTER1_H
