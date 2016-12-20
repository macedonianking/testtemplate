#ifndef CPRIMER_CHAPTER15_TEMPLATE_CHAPTER15_H
#define CPRIMER_CHAPTER15_TEMPLATE_CHAPTER15_H

#include <iterator>

// traits and policy classes.
// traits template.
// facilitate //:促进
// traits // :性质
// elaborate // :阐述

// traits observation
// 1.fixed traits
// 2.have very nature default value.
// 3.traits depend mainly on one or two parameters.
// 4.combine types and constants.
// 5.traits in traits template.

// policy observation.
// 1.orthogonal to other template parameters.
// 2.combine member functions.

namespace template_chapter15 {

// generic template declaration
template<typename T>
struct AccumulateTraits;

template<>
struct AccumulateTraits<char> {
    typedef int type;
};

template<>
struct AccumulateTraits<unsigned char> {
    typedef int type;
};

template<>
struct AccumulateTraits<signed char> {
    typedef int type;
};

template<>
struct AccumulateTraits<short> {
    typedef int type;
};

template<>
struct AccumulateTraits<unsigned short> {
    typedef int type;
};

template<>
struct AccumulateTraits<float> {
    typedef double type;

    static const type zero() {
        return 0.0;
    }
};

template<typename T>
struct AccumulateTraits {
    typedef T type;

    static const type zero() {
        return type();
    }
};

template<typename T>
inline typename AccumulateTraits<T>::type
accumulate(const T *begin, const T *end) {
    typename AccumulateTraits<T>::type total = typename AccumulateTraits<T>::type();
    for (; begin != end; ++begin) {
        total += *begin;
    }
    return total;
}

// 增加策略代码
template<typename T, typename Policy, typename Traits = AccumulateTraits<T>>
struct Accumulate {
public:
    typedef typename Traits::type type;
    static type accumulate(const T *begin, const T *end) {
        type total = Traits::zero();
        for (; begin != end; ++begin) {
            Policy::accumulate(total, *begin);
        }
        return total;
    }
};

class SumPolicy {
public:
    template<typename T1, typename T2>
    static void accumulate(T1 &t1, const T2 &t2) {
        t1 += t2;
    }
};

class MultiPolicy {
public:
    template<typename T1, typename T2>
    static void accumulate(T1 &t1, const T2 &t2) {
        t1 *= t2;
    }
};

void chapter15_1_tutorial();

}

namespace chapter15_1_6 {

template<typename T1, typename T2>
class SumPolicy {
public:
    static void accumulate(T1 &t1, const T2 &t2) {
        t1 += t2;
    }
};

template<typename T1, typename T2>
class MultiPolicy {
public:
    static void accumulate(T1 &t1, const T2 &t2) {
        t1 *= t2;
    }
};

// 使用template template class来做policy
template<typename T, 
    template<typename, typename> class Policy = SumPolicy,
    typename Traits = typename template_chapter15::AccumulateTraits<T>>
class Accumulate {
public:
    typedef typename Traits::type type;
    type accumulate(const T* begin, const T* end) {
        type total = Traits::zero();
        for (; begin != end; ++begin) {
            Policy<type, T>::accumulate(total, *begin);
        }
    }
};

template<typename T>
inline typename std::iterator_traits<T>::value_type
accumulate_iterator(T begin, T end) {
    typedef typename std::iterator_traits<T>::value_type value_type;
    value_type total = value_type();
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

}

#endif // CPRIMER_CHAPTER15_TEMPLATE_CHAPTER15_H
