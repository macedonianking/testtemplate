#include "chapter12/chapter12.h"

namespace chapter12 {

double SalesItem::Average() const {
    if (!mCount) {
        return 0.0;
    } else {
        return mRevenue / mCount;
    }
}



}
