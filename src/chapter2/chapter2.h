#ifndef MAIN_CHAPTER2_H
#define MAIN_CHAPTER2_H

#include <string>
#include <iostream>

class SalesItem2 {
public:
	SalesItem2() {}
	SalesItem2(const std::string &isbn, int count, double revenue);

	SalesItem2 operator+(const SalesItem2 &rhs) const;
	SalesItem2 &operator=(const SalesItem2 &rhs);

	bool SameISBN(const SalesItem2 &rhs) const;
	double Avenue() const;

	friend std::istream &operator>>(std::istream &in, SalesItem2 &rhs);
	friend std::ostream &operator<<(std::ostream &out, const SalesItem2 &rhs);
private:
	std::string mISBN;
	int 		mCount;
	double 		mRevenue;
};

std::istream &operator>>(std::istream &in, SalesItem2 &rhs);
std::ostream &operator<<(std::ostream &out, const SalesItem2 &rhs);


template<typename T>
const T &max(const T &lhs, const T &rhs) {
	std::cout << "const T &max(const T &lhs, const T &rhs)" << std::endl;
	return lhs < rhs ? rhs : lhs;
}

template<typename T>
T &max(T &lhs, T &rhs) {
	std::cout << "T &max(T &lhs, T &rhs)" << std::endl;
	return lhs < rhs ? rhs : lhs;
}

void chapter2_3_problem();
void chapter2_1_1_tutorial();

#endif // MAIN_CHAPTER2_H
