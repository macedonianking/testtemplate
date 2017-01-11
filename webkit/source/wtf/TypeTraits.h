#ifndef WTF_TypeTraits_h
#define WTF_TypeTraits_h

namespace WTF {

template<bool _judge, typename T>
struct EnableIf;

template<typename T>
struct EnableIf<true, T> {
public:
    typedef T type;
};

template<typename From, typename To>
class IsPointerConvertible {
private:
    static char test(To *);
    static int  test(...);

public:
    static constexpr bool value = (sizeof(test(static_cast<From*>(0))) == sizeof(char));
};

#define EnsurePtrConvertibleArgDecl(From, To) \
    typename WTF::EnableIf<WTF::IsPointerConvertible<From, To>::value, bool>::type = true
#define EnsurePtrConvertibleArgDefn(From, To) \
    typename WTF::EnableIf<WTF::IsPointerConvertible<From, To>::value, bool>::type

}

#endif // WTF_TypeTraits_h
