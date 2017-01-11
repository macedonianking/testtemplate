#ifndef WTF_Compiler_h
#define WTF_Compiler_h

#define LIKELY(x) x

// 是否定义了编译器
#define COMPILER(WTF_FEATURE) (defined(WTF_COMPILER_##WTF_FEATURE) && WTF_COMPILER_##WTF_FEATURE)

#if COMPILER(GCC)
#define WTF_PRETTY_FUNCTION __FUNCTION__
#else
#define WTF_PRETTY_FUNCTION __FUNCTION__
#endif

#endif