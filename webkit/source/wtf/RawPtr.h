#ifndef WEBKIT_SORUCE_WTF_RAWPTR_H
#define WEBKIT_SORUCE_WTF_RAWPTR_H

#include <stdint.h>
#include <cstddef>

#include "Config.h"
#include "wtf/HashTableDeletedValueType.h"

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

    template<typename U>
    RawPtr(const RawPtr<U> &t)
    : m_ptr(t.get()) 
    {
    }

    // 设置成-1
    RawPtr(HashTableDeletedValueType) : m_ptr(hashTableDeletedValue()) {
    }
    bool isHashTableDeletedValue() const {
        return m_ptr == hashTableDeletedValue();
    }

    T *get() const {
        return m_ptr;
    }
    void clear() { m_ptr = 0; }

    // FIXME: oilpan.
    // Take ownership of the internal pointer.
    RawPtr<T> release() {
        RawPtr<T> tmp(m_ptr);
        m_ptr = 0;
        return tmp;
    }

    static T *hashTableDeletedValue() {
        return reinterpret_cast<T*>(-1);
    }
private:
    T   *m_ptr;
    static const uintptr_t  rawPtrZapValue = 0x3a3a3a3a;
};

}

#endif // WEBKIT_SORUCE_WTF_RAWPTR_H
