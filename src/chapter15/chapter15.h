#ifndef MAIN_CHAPTER15_CHAPTER15_H
#define MAIN_CHAPTER15_CHAPTER15_H

#include <string>
#include <iostream>

class BaseItem {
public:
    BaseItem();
    explicit BaseItem(const std::string &isbn, const std::string &name, double price);
    
    const std::string &ISBN() const {
        return mISBN;
    }

    virtual void Initialize(std::istream &in);
    virtual double NetPrice(int count) const;

    void PrintOrder(std::ostream &out, int count) const;
private:
    std::string         mISBN;
    std::string         mName;
    double              mPrice;
};

class BulkItem : public BaseItem
{
public:
    BulkItem();
    BulkItem(const std::string &isbn, const std::string &name, double price, double discount);

    virtual void Initialize(std::istream &in);
    virtual double NetPrice(int count) const;
private:
    double mDiscount;
};

void chapter15_1_tutorial();

#endif