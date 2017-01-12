#include "wtf/Assertions.h"

#include <stdarg.h>
#include <stdio.h>

#if OS(LINUX)
#include <execinfo.h>
#include <alloca.h>
#include <dlfcn.h>
#elif OS(WIN)
#include <malloc.h>
#endif

static WTFCrashHookFunction globleHook = 0;

static void vprintf_stderr_common(const char *format, va_list args) {
    vfprintf(stdout, format, args);
}

static void printf_stderr_common(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf_stderr_common(format, args);
    va_end(args);
}

static void printCallSite(const char *file, int line, const char *function) {
    printf_stderr_common("%s(%d): %s\n", file, line, function);
}

void WTFReportAssertionFailure(const char *file, int line, const char *function, const char *assertion) {
    if (assertion) {
        printf_stderr_common("ASSERTION FAILED: %s\n", assertion);
    } else {
        printf_stderr_common("SHOULD NEVER BE REACHED\n");
    }
    printCallSite(file, line, function);
}

static void WTFGetBacktrace(void **frames, int *size) {
#if OS(LINUX)
    *size = backtrace(frames, *size);
#else
    *size = 0;
#endif
}

static void WTFPrintStacktrace(void **samples, int size) {
    int index;

    for (int i = 0; i < size; ++i) {
        WTF::FrameToNameScope scope(samples[i]);
        index = i + 1;
        if (scope.nullableName()) {
            fprintf(stderr, "%-3d %p %s\n", index, samples[i], scope.nullableName());
        } else {
            fprintf(stderr, "%-3d %p", index, samples[i]);
        }
    }
}

/**
* 报告堆栈
*/
void WTFReportBacktrace(int framesToShow) {
    static const int framesToSkip = 2;
    int frames = framesToShow + framesToSkip;
    void **samples = static_cast<void**>(alloca(frames * sizeof(void*)));

    WTFGetBacktrace(samples, &frames);
    WTFPrintStacktrace(samples, frames);
}

void WTFSetCrashHook(WTFCrashHookFunction hook) {
    globleHook = hook;
}

void WTFInvokeCrashHook() {
    if (globleHook) {
        globleHook();
    }
}

WTF::FrameToNameScope::FrameToNameScope(void *addr)
: m_name(0) {
#if OS(LINUX)
    Dl_info info;
    if (!dladdr(addr, &info) || !info.dl_sname) {
        return; 
    }
    m_name = info.dl_sname;
#endif
}

WTF::FrameToNameScope::~FrameToNameScope() {
}
