#ifndef CHAPTER15_TEMPLATE_CHAPTER15_2_H
#define CHAPTER15_TEMPLATE_CHAPTER15_2_H

#include <cstddef>

// type function.
// promition traits.

namespace template_chapter15_2 {

template<typename T>
struct TypeSize {
public:
    static const size_t value = sizeof(T);
};

// Get container value_type.
template<typename T>
struct ContainerType {
public:
    typedef typename T::value_type      value_type;
    typedef typename T::const_iterator  const_iterator;
    typedef typename T::iterator        iterator;
};

// get the total sum of the container.
template<typename T>
inline typename ContainerType<T>::value_type sum_of_container(const T &t) {
    typedef typename ContainerType<T>::value_type value_type;

    value_type result = value_type();
    typename ContainerType<T>::const_iterator iter;
    typename ContainerType<T>::const_iterator end = t.end();
    for (iter = t.begin(); iter != end; ++iter) {
        result += *iter;
    }
    
    return result;
}

// check whether T is a class type.
template<typename T>
struct IsClass {
private:
    template<typename U>
    static char test(int U::*);
    template<typename U>
    static int  test(...);
    
public:
    static constexpr bool value = (sizeof(IsClass<T>::test(0)) == sizeof(char));
};

template<typename T>
struct RemoveReference {
public:
    typedef T type;
    typedef T &reference;
};

template<typename T>
struct RemoveReference<T&> {
public:
    typedef T type;
    typedef T &reference;
};

template<>
struct RemoveReference<void> {
public:
};

// 模板申明
template<typename T1, typename T2>
struct Promotion;

// PromotionImpl declaration.
template<bool _T1IsClass, bool _T2IsClass, typename T1, typename T2>
struct PromotionImpl;

template<bool _SELECT, typename T1, typename T2> 
struct SelectType{
public:
    typedef T1 type;
};

template<typename T1, typename T2>
struct SelectType<false, T1, T2> {
public:
    typedef T2 type;
};

template<typename T1, typename T2>
struct Promotion {
public:
    typedef typename PromotionImpl<IsClass<T1>::value, IsClass<T2>::value, T1, T2>::type type;
};

// 模板的一个特化
template<typename T>
struct Promotion<T, T> {
public:
    typedef T type;
};

// 如果都是基本类型，那么用size来解决使用谁的类型
template<typename T1, typename T2>
struct PromotionImpl<false, false, T1, T2> {
public:
    typedef typename SelectType<(sizeof(T1) > sizeof(T2)), T1, T2>::type type;
};

// T1是基本类型, T2是类
template<typename T1, typename T2>
struct PromotionImpl<false, true, T1, T2> {
public:
    typedef T2 type;
};

// T1是类,T2是基本类型
template<typename T1, typename T2>
struct PromotionImpl<true, false, T1, T2> {
public:
    typedef T1 type;
};

// T1的指针是否能够被T2赋值
template<typename T1, typename T2>
struct IsPointerAssignableFrom {
private:
    template<typename U>
    static char test(U *);
    template<typename U>
    static int  test(...);
    
public:
    static constexpr bool value = sizeof(test<T1>(static_cast<T2*>(0))) == sizeof(char);
};

// T1, T2都是类类型, 如果T2的指针能够赋值给T1(T1是基类型，T2是派生类型),那么使用T2的类型
// 否则使用T1类型
template<typename T1, typename T2>
struct PromotionImpl<true, true, T1, T2> {
public:
    typedef typename SelectType<
        IsPointerAssignableFrom<T1, T2>::value,
        T2,
        T1
    >::type type;
};

void template_chapter15_2_tutorial();

}

#endif // CHAPTER15_TEMPLATE_CHAPTER15_2_H
