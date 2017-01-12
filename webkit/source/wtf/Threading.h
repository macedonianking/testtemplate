#ifndef WTF_Threading_h
#define WTF_Threading_h

#include "wtf/Assertions.h"

#if OS(WIN)
#include <stdint.h>
#elif OS(LINUX)
#include <pthread.h>
#else
#error "UNNOWN OS"
#endif

#if OS(WIN)
typedef uintptr_t   ThreadIdentifier;
#else
typedef pthread_t   ThreadIdentifier;
#endif

namespace WTF {
    
ThreadIdentifier CurrentThread();

}

#endif // WTF_Threading_h
