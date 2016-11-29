#include "chapter1/chapter1.h"

#include "macros.h"

void chapter1_2_2_problem() {
	int a, b;
	
	std::cout << "Enter two numbers:\n";
	std::cin >> a >> b;
	std::cout << "The result is " << (a + b) << std::endl;
}

void SalesItem::AddAvenue(int count, double revenue) {
	this->mCount += count;
	this->mRevenue += revenue;
}

std::istream &operator>>(std::istream &in, SalesItem &item) {
	in >> item.mISBN >> item.mCount >> item.mRevenue;
	return in;
}

std::ostream &operator<<(std::ostream &out, const SalesItem &item) {
	return out << item.mISBN << " " << item.mCount << " " << item.Avenue();
}

SalesItem SalesItem::operator+(const SalesItem &rhs) const {
	SalesItem result = *this;
	result.mCount += rhs.mCount;
	result.mRevenue += rhs.mRevenue;
	return result;
}

SalesItem &SalesItem::operator+=(const SalesItem &rhs) {
	DCHECK(SameISBN(rhs));
	this->mRevenue += rhs.mRevenue;
	this->mCount += rhs.mCount;
	return *this;
}

void chapter1_read_SalesItem() {
	SalesItem item1, item2;
	std::cout << "Enter two sales item:" << std::endl;
	std::cin >> item1 >> item2;
	if  (item1.SameISBN(item2)) {
		std::cout << item1 + item2 << std::endl;
	} else {
		std::cout << "Different ISBN" << std::endl;
	}
}

static SalesItem *find_same_isbn_item(SalesItem **ptr, const SalesItem &item, int n) {
	for (int i = 0; i < n; ++i, ++ptr) {
		if ((*ptr)->SameISBN(item)) {
			return *ptr;
		}
	}
	return NULL;
}

void chapter1_24_problem() {
	SalesItem *itemBuf[100];
	SalesItem *item, temp;
	int n;

	n = 0;
	for (int i = 0; i < 100; ++i) {
		std::cin >> temp;
		item = find_same_isbn_item(itemBuf, temp, n);
		if (item != NULL) {
			*item += temp;
		} else {
			item = new SalesItem(temp);
			itemBuf[n++] = item;
		}
	}

	for (int i = 0; i < n; ++i) {
		delete itemBuf[i];
		itemBuf[i] = NULL;
	}
}

void chapter1_6_tutorial() {
	SalesItem sum, tmp;

	if (std::cin >> sum) {
		while (std::cin >> tmp) {
			if (sum.SameISBN(tmp)) {
				sum += tmp;
			} else {
				std::cout << sum << std::endl;
				sum = tmp;
			}
		}
		std::cout << sum << std::endl;
	}
}

