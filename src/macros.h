#ifndef MAIN_MACROS_H
#define MAIN_MACROS_H

#define DCHECK(condition)

#define DISALLOW_COPY_AND_ASSIGN(T) \
    T(const T&); \
    T &operator=(const T &)

#endif // MAIN_MACROS_H
