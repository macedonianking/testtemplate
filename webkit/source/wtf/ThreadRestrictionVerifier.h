#ifndef ThreadRestrictionVerifier_h
#define ThreadRestrictionVerifier_h

#if ENABLE(ASSERT)
#include <wtf/Threading.h>

namespace WTF {

class ThreadRestrictionVerifier {
public:
    ThreadRestrictionVerifier() 
    : m_shared(false)
    , m_owningThread(0)
    {
    }

    /**
     * shared模式是多线程使用的模式，在多线程模式的情况下对象有一个拥有者线程
     */
    void setShared(bool shared) {
        bool previouslyShared = m_shared;
        m_shared = shared;

        if (!m_shared) {
            return;
        }
        ASSERT(m_shared != previouslyShared);
        m_owningThread = CurrentThread();
    }

    /**
     * 当前线程是否能够通过验证
     */
    bool isSafeToUse() const {
        if (!m_shared) {
            return true;
        }
        return m_owningThread == CurrentThread();
    }

private:
    bool                m_shared;
    ThreadIdentifier    m_owningThread;
};

}

#endif // ENABLE(ASSERT)

#endif // ThreadRestrictionVerifier_h
