#ifndef CHAPTER15_TEMPLATE_CHAPTER15_3_H
#define CHAPTER15_TEMPLATE_CHAPTER15_3_H

#include "chapter15/template_chapter15_2.h"

namespace template_chapter15_3 {

// T1(const T2&)
template<typename T1, typename T2>
struct IsClassConstructableFrom {
private:
    template<typename U>
    static char test(const U&);
    static int  test(...);

public:
    static const bool value = sizeof(test<T1>(*static_cast<T2*>(0))) == sizeof(char);  
};

// 参数类型
template<typename T>
struct ParameterType {
public:
    typedef typename template_chapter15_2::SelectType<
        template_chapter15_2::IsClass<T>::value, 
        const T &,
        T
    >::type type;
};

template<typename T, bool IsClass>
struct CopyMovePolicy;

void template_chapter15_3_tutorial();

};

#endif // CHAPTER15_TEMPLATE_CHAPTER15_3_H
