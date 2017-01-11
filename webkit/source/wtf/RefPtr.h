#ifndef WTF_RefPtr_h
#define WTF_RefPtr_h

#include <algorithm>
#include <cstddef>

#include "wtf/HashTableDeletedValueType.h"
#include "wtf/RawPtr.h"
#include "wtf/PassRefPtr.h"
#include "wtf/NullPtr.h"
#include "wtf/TypeTraits.h"

namespace WTF {

template<typename>
class PassRefPtr;

template<typename T>
class RefPtr {
private:
    WTF_DISALLOW_CONSTRUCTOR_FROM_ZERO(RefPtr);
    WTF_DISALLOW_ASSIGN_FROM_ZERO(RefPtr);

public:
    RefPtr() : m_ptr(0) {}
    RefPtr(std::nullptr_t): m_ptr(0) {}
    RefPtr(T *ptr): m_ptr(ptr) {
        refIfNotNull(m_ptr);
    }
    template<typename U>
    RefPtr(const RawPtr<U> &u, EnsurePtrConvertibleArgDecl(U, T)) : m_ptr(u.get()) {
        refIfNotNull(m_ptr);
    }
    explicit RefPtr(T &ref) : m_ptr(&ref) {
        refIfNotNull(m_ptr);
    }
    RefPtr(const RefPtr<T> &ref) : m_ptr(ref.m_ptr) {
        refIfNotNull(m_ptr);
    }
    template<typename U>
    RefPtr(const RefPtr<U> &u, EnsurePtrConvertibleArgDecl(U, T))
    : m_ptr(u.get()) {
        refIfNotNull(m_ptr);
    }

    template<typename U>
    RefPtr(const PassRefPtr<U> &ref, EnsurePtrConvertibleArgDecl(U, T))
    : m_ptr(ref.leakRef()) {
    }

    ~RefPtr() {
        derefIfNotNull(m_ptr);
    }

    /**
    * 可能是放在HashTable里面用来标示空值的
    */
    RefPtr(HashTableDeletedValueType) : m_ptr(hashTableDeletedValue()) {}
    bool isHashTableDeletedValue() const {
        return m_ptr == hashTableDeletedValue();
    }

    /**
    * 位置的bool类型，用来判断是否有函数成员
    */
    typedef T *(RefPtr<T>::*UnspecifiedBoolType)() const;
    operator UnspecifiedBoolType() const {
        return m_ptr ? &RefPtr<T>::get : 0;
    }

    T *get() const {
        return m_ptr;
    }

    // clear the reference
    void clear();
    PassRefPtr<T> release() {
        PassRefPtr<T> o = adoptRef(m_ptr);
        m_ptr = 0;
        return 0;
    }

    T &operator*() const {
        return *m_ptr;
    }
    bool operator!() const {
        return !m_ptr;
    }

    T *operator->() const {
        return m_ptr;
    }

    RefPtr<T> &operator=(T *);
    RefPtr<T> &operator=(const RefPtr<T> &);
    RefPtr<T> &operator=(std::nullptr_t) {
        clear();
        return *this;
    }

    template<typename U>
    RefPtr<T> &operator=(const RefPtr<U> &ref);
    template<typename U>
    RefPtr<T> &operator=(const RawPtr<U> &ref);

    void swap(RefPtr<T> &ref);
private:
    static T *hashTableDeletedValue() {
        return reinterpret_cast<T*>(-1);
    }

private:
    T *m_ptr;
};

template<typename T>
void RefPtr<T>::clear() {
    T *ptr = m_ptr;
    m_ptr = 0;
    derefIfNotNull(ptr);
}

template<typename T>
RefPtr<T> &RefPtr<T>::operator=(T *ptr) {
    RefPtr<T> temp(ptr);
    swap(temp);
    return *this;
}

template<typename T>
RefPtr<T> &RefPtr<T>::operator=(const RefPtr<T> &ref) {
    RefPtr<T> temp(ref.get());
    swap(temp);
    return *this;
}

template<typename T>
void RefPtr<T>::swap(RefPtr<T> &ref) {
    T *ptr = ref.m_ptr;
    ref.m_ptr = m_ptr;
    m_ptr = ptr;
}

template<typename T>
template<typename U>
RefPtr<T> &RefPtr<T>::operator=(const RefPtr<U> &ref) {
    RefPtr<T> temp(ref.get());
    swap(temp);
    return *this;
}

template<typename T>
template<typename U>
RefPtr<T> &RefPtr<T>::operator=(const RawPtr<U> &ref) {
    RefPtr<T> temp(ref.get());
    swap(temp);
    return *this;
}

template<typename T, typename U>
inline RefPtr<T> static_pointer_cast(const RefPtr<U> &u) {
    return RefPtr<T>(static_cast<T*>(u.get()));
}

template<typename T>
inline T *getPtr(const RefPtr<T> &ref) {
    return ref.get();
}

/**
 * 提供的公共的组件，能够取到对应的指针
 */
template<typename T>
class RefPtrValuePeeker {
    WTF_DISALLOW_CONSTRUCTION_FROM_ZERO(RefPtrValuePeeker);
    WTF_DISALLOW_ZERO_ASSIGNMENT(RefPtrValuePeeker);
    
public:
    RefPtrValuePeeker() : m_ptr(0) {}
    RefPtrValuePeeker(std::nullptr_t) : m_ptr(0) {}
    RefPtrValuePeeker(const RefPtr<T> &ref) : m_ptr(ref.get()) {}
    RefPtrValuePeeker(const PassRefPtr<T> &ref) : m_ptr(ref.get()) {}

    operator T*() const {
        return m_ptr;
    }
private:
    T *m_ptr;
};

}

using WTF::RefPtr;
using WTF::static_pointer_cast;

#endif
