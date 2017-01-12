#ifndef WTF_Assertions_h
#define WTF_Assertions_h

#include "Config.h"
#include "Compiler.h"

typedef void (*WTFCrashHookFunction)();

void WTFReportAssertionFailure(const char *filename, int line, const char *function, const char *assertion);
void WTFReportBacktrace(int famesToShow = 31);
void WTFSetCrashHook(WTFCrashHookFunction);
void WTFInvokeCrashHook();

#ifndef IMMEDIATE_CRASH
#if COMPILER(GCC)
#define IMMEDIATE_CRASH() __builtin_trap()
#else
#define IMMEDIATE_CRASH() ((void (*)())0)()
#endif // COMPILER(GCC)
#endif // IMMEDIATE_CRASH

#ifndef CRASH
#define CRASH() \
do { \
    WTFReportBacktrace(); \
    WTFInvokeCrashHook(); \
    *(int*)0 = 0xbaadbeef; \
    IMMEDIATE_CRASH(); \
} while(0)
#endif // CRASH

#if COMPILER(GCC)
#define WTF_ATTRIBUTE_PRINTF(formatStringArgument, extraArguments) __attribute__((__fomrat__(printf, formatStringArgument, extraArguments)))
#else
#define WTF_ATTRIBUTE_PRINTF(fomratStringArgument, extraArguments)
#endif

#if ENABLE(ASSERT)
#define ASSERT(assertion) \
do { \
if (!(assertion)) { \
    WTFReportAssertionFailure(__FILE__, __LINE__, WTF_PRETTY_FUNCTION, #assertion); \
    CRASH(); \
} \
} while(0)
#else
#define ASSERT(assertion) 
#endif

#ifdef ADDRESS_SANTINIZER

#define ASSERT_WITH_SECURITY_IMPLICATION(assertion) \
do { \
    if (!(assertion)) { \
        WTFReportAssertionFailure(__FILE__, __LINE__, WTF_PRETTY_FUNCTION, #assertion); \
        CRASH(); \
    } \
} while(0)

#else

#define ASSERT_WITH_SECURITY_IMPLICATION(assertion) ASSERT(assertion)

#endif // ADDRESS_SANTINIZER

namespace WTF {

class FrameToNameScope {
public:
    explicit FrameToNameScope(void *addr);
    ~FrameToNameScope();

    const char *nullableName() const {
        return m_name;
    }

private:
    const char *m_name;
};

}

#endif
