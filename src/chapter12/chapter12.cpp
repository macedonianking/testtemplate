#include "chapter12/chapter12.h"

namespace chapter12 {

double SalesItem::Average() const {
    if (!mCount) {
        return 0.0;
    } else {
        return mRevenue / mCount;
    }
}

SalesItem::SalesItem(std::istream &in) {
    in >> mISBN >> mRevenue >> mCount;
}

bool SalesItem::SameISBN(const SalesItem &item) const {
    return mISBN == item.mISBN;
}

std::ostream &operator<<(std::ostream &out, const SalesItem &item) {
    out << "Name: " << item.mISBN << std::endl
        << "Average: " << item.Average() << std::endl
        << "Count: " << item.mCount << std::endl
        << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, SalesItem &item) {
    return in >> item.mISBN >> item.mRevenue >> item.mCount;
}

}
