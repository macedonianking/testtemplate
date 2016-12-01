#ifndef WEBKIT_SORUCE_WTF_RAWPTR_H
#define WEBKIT_SORUCE_WTF_RAWPTR_H

#include <stdint.h>
#include <cstddef>

#include "Config.h"

namespace WTF {

template<typename T>
class RawPtr {
public:
    RawPtr() {
#if ENABLE(ASSERT)
        m_ptr = reinterpret_cast<T*>(rawPtrZapValue);
#endif
    }
    RawPtr(std::nullptr_t) : m_ptr(0) {}
    RawPtr(T *ptr) : m_ptr(ptr)  {}
    explicit RawPtr(T &reference) : m_ptr(&reference) {}
    RawPtr(const RawPtr<T> &t) 
    : m_ptr(t.get()){
    }

    T *get() const {
        return m_ptr;
    }

private:
    T   *m_ptr;
    static const uintptr_t  rawPtrZapValue = 0x3a3a3a3a;
};

}

#endif // WEBKIT_SORUCE_WTF_RAWPTR_H
