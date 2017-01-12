#include "wtf/Threading.h"

#if OS(LINUX)
#include <pthread.h>
#elif OS(WIN)
#include <windows.h>
#endif

namespace WTF {

ThreadIdentifier CurrentThread() {
#if OS(LINUX)
    return static_cast<ThreadIdentifier>(pthread_self());
#elif OS(WIN)
    return static_cast<ThreadIdentifier>(GetCurrentThreadId());
#endif
}

}
