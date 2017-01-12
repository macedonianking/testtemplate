#ifndef WTF_RefCounted_h
#define WTF_RefCounted_h

#include "wtf/Assertions.h"
#include "wtf/Noncopyable.h"

#if ENABLE(ASSERT)
#define CHECK_REF_COUNTED_LIFECYCLE    1
#include "wtf/ThreadRestrictionVerifier.h"
#else
#define CHECK_REF_COUNTED_LIFECYCLE    0
#endif

namespace WTF {

/**
 * 如果应用计数是1，那么是单线程使用，如果超过1，那么是多线程使用，那么禁止在非拥有者线程里面，
 * 增加或者减少引用计数
 */
class RefCountedBase {
public:
    void ref() {
#if CHECK_REF_COUNTED_LIFECYCLE
        /**
         * 一般情况下在多线程情况下使用,所以设置为共享的状态
         */
        if (m_refCount == 1) {
            m_verifier.setShared(true);
        }
        ASSERT(m_verifier.isSafeToUse());
        ASSERT(!m_adoptionIsRequired);
#endif
#if ENABLE(SECURITY_ASSERT)
        ASSERT_WITH_SECURITY_IMPLICATION(!m_deletionHasBegun);
#endif
        ++m_refCount;      
    }

    bool hasOneRef() const {
#if ENABLE(SECURITY_ASSERT)
        ASSERT_WITH_SECURITY_IMPLICATION(!m_deletionHasBegun);
#endif
#if CHECK_REF_COUNTED_LIFECYCLE
        ASSERT(!m_verifier.isSafeToUse());
#endif
        return m_refCount == 1;
    }

    int refCount() const {
#if CHECK_REF_COUNTED_LIFECYCLE
        ASSERT(m_verifier.isSafeToUse());
#endif
        return m_refCount;
    }

protected:
    RefCountedBase() 
    : m_refCount(1)
#if ENABLE(SECURITY_ASSERT)
    , m_deletionHasBegun(false)
#endif
#if CHECK_REF_COUNTED_LIFECYCLE
    , m_adoptionIsRequired(true)
#endif
    {
    }

    ~RefCountedBase() {
#if ENABLE(SECURITY_ASSERT)
        ASSERT_WITH_SECURITY_IMPLICATION(m_deletionHasBegun);
#endif
#if CHECK_REF_COUNTED_LIFECYCLE
        ASSERT(!m_adoptionIsRequired);
#endif
    }

    bool derefBase() {
#if ENABLE(SECURITY_ASSERT)
        ASSERT_WITH_SECURITY_IMPLICATION(!m_deletionHasBegun);
#endif
#if CHECK_REF_COUNTED_LIFECYCLE
        ASSERT(m_verifier.isSafeToUse());
        ASSERT(!m_adoptionIsRequired);
#endif
        ASSERT(m_refCount > 0);
        if (!--m_refCount) {
#if ENABLE(SECURITY_ASSERT)
            m_deletionHasBegun = true;
#endif
            return true;
        }

#if CHECK_REF_COUNTED_LIFECYCLE
        if (m_refCount == 1) {
            /**
             * 如果引用计数为1，那么是单线程使用，如果应用计数超过1，那么是多线程使用
             */
            m_verifier.setShared(false);
        }
#endif
        return false;
    }

#if CHECK_REF_COUNTED_LIFECYCLE
    bool deletionHasBegun() const {
        return m_deletionHasBegun;
    }
#endif

#if CHECK_REF_COUNTED_LIFECYCLE || ENABLE(SECURITY_ASSERT)
    friend void adopted(RefCountedBase *base);
#endif

private:
    int m_refCount;
#if ENABLE(SECURITY_ASSERT)
    bool m_deletionHasBegun;
#endif
#if CHECK_REF_COUNTED_LIFECYCLE
    bool m_adoptionIsRequired;
    ThreadRestrictionVerifier m_verifier;
#endif
};

#if CHECK_REF_COUNTED_LIFECYCLE || ENABLE(SECURITY_ASSERT)
inline void adopted(RefCountedBase* object)
{
    if (!object)
        return;
    ASSERT_WITH_SECURITY_IMPLICATION(!object->m_deletionHasBegun);
#if CHECK_REF_COUNTED_LIFECYCLE
    object->m_adoptionIsRequired = false;
#endif
}
#endif

template<typename T>
class RefCounted : public RefCountedBase {
    WTF_MAKE_NONCOPYABLE(RefCounted);
public:

};

} // namespace WTF

#endif
