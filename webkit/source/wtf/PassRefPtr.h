#ifndef WEBKIT_SOURCE_WTF_PASS_REF_PTR_H
#define WEBKIT_SOURCE_WTF_PASS_REF_PTR_H

#include "wtf/RawPtr.h"
#include "wtf/NullPtr.h"
#include "wtf/TypeTraits.h"

namespace WTF {

inline void requireAdoption(const void *) {
}

inline void adopted(const void *) {
}

template<typename T>
inline void refIfNotNull(T *ptr) {
    if (ptr != 0) {
        requireAdoption(ptr);
        ptr->ref();
    }
}

template<typename T>
inline void derefIfNotNull(T *ptr) {
    if (ptr) {
        ptr->deref();
    }
}

template<typename T>
class PassRefPtr {
private:
    WTF_DISALLOW_CONSTRUCTOR_FROM_ZERO(PassRefPtr);
    WTF_DISALLOW_ASSIGN_FROM_ZERO(PassRefPtr);
    
public:
    
};

}

#endif