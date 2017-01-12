#ifndef WTF_Noncopyable_h
#define WTF_Noncopyable_h

#define WTF_MAKE_NONCOPYABLE(ClassName) \
private: \
    ClassName(const ClassName &); \
    ClassName &operator=(const ClassName &);

#endif // WTF_Noncopyable_h
