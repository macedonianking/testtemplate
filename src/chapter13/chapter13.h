#ifndef CPRIMER_CHAPTER13_CHAPTER13_H
#define CPRIMER_CHAPTER13_CHAPTER13_H

#include <string>

#include "macros.h"

namespace chapter13 {

class SalesItem {
public:
    SalesItem() {
    }

private:
    std::string     mISBN;
    double          mRevenue;
    int             mCount;

    DISALLOW_COPY_AND_ASSIGN(SalesItem);
};

class NoName {
public:
    NoName() : mName(new std::string), mAge(0), mTall(0) {
    }

    NoName(const NoName &item) 
    : mName(new std::string(*item.mName)),
      mAge(item.mAge),
      mTall(item.mTall) {
    } 

    ~NoName() {
        delete mName;
        mName = NULL;
    }

    NoName &operator=(const NoName &item);

private:
    std::string     *mName;
    int             mAge;
    double          mTall;    
};

}

#endif // CPRIMER_CHAPTER13_CHAPTER13_H
