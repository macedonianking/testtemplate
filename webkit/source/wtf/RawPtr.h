#ifndef WTF_RawPtr_h
#define WTF_RawPtr_h

#include <stdint.h>
#include <cstddef>
#include <algorithm>

#include "Config.h"
#include "wtf/HashTableDeletedValueType.h"
#include "wtf/NullPtr.h"

namespace WTF {

template<typename T>
class RawPtr {
    WTF_DISALLOW_CONSTRUCTION_FROM_ZERO(RawPtr);
    WTF_DISALLOW_ZERO_ASSIGNMENT(RawPtr);

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

    T* leakRef() {
        T *ptr = m_ptr;
        m_ptr = 0;
        return ptr;
    }

    T *leakPtr() {
        T *ptr = m_ptr;
        m_ptr = 0;
        return ptr;
    }

    template<typename U>
    RawPtr<T> &operator=(U *ptr) {
        m_ptr = ptr;
        return *this;
    }

    template<typename U>
    RawPtr<T> &operator=(const RawPtr<U> &t) {
        m_ptr = t.get();
        return *this;
    }

    RawPtr<T> &operator=(std::nullptr_t) {
        m_ptr = 0;
        return *this;
    }

    operator T*() const {
        return m_ptr;
    }
    T *operator->() const {
        return m_ptr;
    }
    T &operator*() const {
        return *m_ptr;
    }
    bool operator!() const {
        return !m_ptr;
    }

    void swap(RawPtr<T> &o) {
        std::swap(m_ptr, o.m_ptr);
    }

    static T *hashTableDeletedValue() {
        return reinterpret_cast<T*>(-1);
    }
private:
    static const uintptr_t  rawPtrZapValue = 0x3a3a3a3a;
    T   *m_ptr;
};

template<typename T, typename U>
inline RawPtr<T> static_pointer_cast(const RawPtr<U> &o) {
    return RawPtr<T>(static_cast<T*>(o.get()));
}

template<typename T>
inline T* getPtr(const RawPtr<T> &t) {
    return t.get();
}

}

// Import RawPtr name to transination unit.
using WTF::RawPtr;

#endif // WEBKIT_SORUCE_WTF_RAWPTR_H
