#ifndef WTF_Assertions_h
#define WTF_Assertions_h

#include "Config.h"
#include "Compiler.h"

#ifndef IMMEDIATE_TRAP
#define IMMEDIATE_TRAP() \
((void (*)())0)()
#endif

#ifndef CRASH
#define CRASH() \
do { \
    WTFReportBacktrace(); \
    WTFInvokeCrashHook(); \
    *(int*)0 = 0xbaadbeef; \
    IMMEDIATE_TRAP(); \
} while(0)
#endif

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

void WTFReportAssertionFailure(const char *filename, int line, const char *assertion);
void WTFReportBacktrace();
void WTFInvokeCrashHook();

#endif
