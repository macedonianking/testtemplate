#include "chapter15/chapter15.h"

BaseItem::BaseItem() {
}

BaseItem::BaseItem(const std::string &isbn, const std::string &name, double price)
: mISBN(isbn),
  mName(name),
  mPrice(price) {
}

void BaseItem::Initialize(std::istream &in) {
    in >> mISBN >> mName >> mPrice;
}

void BaseItem::PrintOrder(std::ostream &out, int count) const {
    out << "ISBN: " << ISBN() 
        << ", " << mName
        << ", TOTAL: " << NetPrice(count)
        << std::endl;  
}

double BaseItem::NetPrice(int count) const {
    return mPrice * count;
}

BulkItem::BulkItem()
: mDiscount(1) {
}

BulkItem::BulkItem(const std::string &isbn, const std::string &name, 
    double price, double discount)
: BaseItem(isbn, name, price),
  mDiscount(discount) {
}

void BulkItem::Initialize(std::istream &in) {
    BaseItem::Initialize(in);
    in >> mDiscount;   
}

double BulkItem::NetPrice(int count) const {
    return BaseItem::NetPrice(count) * mDiscount;
}

void chapter15_1_tutorial() {
    BulkItem item;

    item.Initialize(std::cin);
    item.PrintOrder(std::cout, 12);
}