#include "chapter13/chapter13.h"

namespace chapter13 {

NoName &NoName::operator=(const NoName &item) {
    if (&item == this) {
        return *this;
    }

    delete mName;
    mName = new std::string(*item.mName);
    mAge = item.mAge;
    mTall = item.mTall;
    return *this;
}

}
