#ifndef WEBKIT_SOURCE_WTF_PASS_REF_PTR_H
#define WEBKIT_SOURCE_WTF_PASS_REF_PTR_H

#include "wtf/RawPtr.h"
#include "wtf/NullPtr.h"
#include "wtf/TypeTraits.h"
#include "wtf/Compiler.h"

namespace WTF {

template<typename T> class PassRefPtr;
template<typename T> class RefPtr;
template<typename T> PassRefPtr<T> adoptRef(T *);

inline void adopted(const void *) {
}

inline void requireAdoption(const void *) {
}

template<typename T>
inline void refIfNotNull(T *ptr) {
    if (LIKELY(ptr != 0)) {
        requireAdoption(ptr);
        ptr->ref();
    }
}

template<typename T>
inline void derefIfNotNull(T *ptr) {
    if (LIKELY(ptr)) {
        ptr->deref();
    }
}

template<typename T>
class PassRefPtr {
    WTF_DISALLOW_CONSTRUCTION_FROM_ZERO(PassRefPtr);

public:
    PassRefPtr(): m_ptr(0) {}
    PassRefPtr(std::nullptr_t): m_ptr() {}
    PassRefPtr(T *ptr) : m_ptr(ptr) { refIfNotNull(m_ptr); }
    template<typename U>
    PassRefPtr(const PassRefPtr<U> &u, EnsurePtrConvertibleArgDecl(U, T)): m_ptr(u.get()) {
        refIfNotNull(m_ptr);
    }
    explicit PassRefPtr(T &reference): m_ptr(&reference) {
        refIfNotNull(m_ptr);
    }
    PassRefPtr(const PassRefPtr<T> &o) : m_ptr(o.leakRef()) {}
    ~PassRefPtr() {
        derefIfNotNull(m_ptr);
    }

    template<typename U>
    PassRefPtr(const RawPtr<U> &ref, EnsurePtrConvertibleArgDecl(U, T))
    : m_ptr(ref.get()) {
        refIfNotNull(m_ptr);
    }

    template<typename U>
    PassRefPtr(const RefPtr<U> &ref, EnsurePtrConvertibleArgDecl(U, T));

    T *get() const { return m_ptr; }
    T *leakRef() const { T *ptr = m_ptr; m_ptr = NULL; return ptr; }

    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }
    bool operator!() const { return !m_ptr; }

    typedef T *(PassRefPtr::*UnspecifiedBoolType);
    operator UnspecifiedBoolType() const { return m_ptr ? &PassRefPtr::m_ptr : 0; }

    friend PassRefPtr<T> adoptRef<T>(T *ptr); 

private:
    enum AdoptRefTag { AdoptRef, };
    PassRefPtr(T *ptr, AdoptRefTag): m_ptr(ptr) {}
    PassRefPtr<T> &operator=(const PassRefPtr<T> &);

    mutable T *m_ptr;
};

template<typename T>
template<typename U>
PassRefPtr<T>::PassRefPtr(const RefPtr<U> &ref, EnsurePtrConvertibleArgDefn(U, T))
: m_ptr(ref.get()) {
    refIfNotNull(m_ptr);
}

template<typename T>
PassRefPtr<T> adoptRef(T* ptr) {
    adopted(ptr);
    return PassRefPtr<T>(ptr, PassRefPtr<T>::AdoptRef);
}

template<typename T, typename U>
inline PassRefPtr<T> &static_pointer_cast(const PassRefPtr<U> &o) {
    return adoptRef<T>(o.leakRef());
}


#define OneEqualOp(t1, t2, v1, v2) \
template<typename T, typename U> \
inline bool operator==(t1, t2) { \
    return v1 == v2; \
} \
\
template<typename T, typename U> \
inline bool operator!=(t1, t2) { \
    return v1 != v2; \
}

OneEqualOp(const PassRefPtr<T> &lhs, const PassRefPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const PassRefPtr<T> &lhs, const RefPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const PassRefPtr<T> &lhs, const RawPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const PassRefPtr<T> &lhs, U *rhs, lhs.get(), rhs)

OneEqualOp(const RefPtr<T> &lhs, const PassRefPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const RefPtr<T> &lhs, const RefPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const RefPtr<T> &lhs, const RawPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const RefPtr<T> &lhs, U *rhs, lhs.get(), rhs)

OneEqualOp(const RawPtr<T> &lhs, const PassRefPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const RawPtr<T> &lhs, const RefPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const RawPtr<T> &lhs, const RawPtr<U> &rhs, lhs.get(), rhs.get())
OneEqualOp(const RawPtr<T> &lhs, U *rhs, lhs.get(), rhs)

OneEqualOp(T *lhs, const PassRefPtr<U> &rhs, lhs, rhs.get())
OneEqualOp(T *lhs, const RefPtr<U> &rhs, lhs, rhs.get())
OneEqualOp(T *lhs, const RawPtr<U> &rhs, lhs, rhs.get())

}

using WTF::PassRefPtr;
using WTF::static_pointer_cast;
using WTF::adoptRef;

#endif