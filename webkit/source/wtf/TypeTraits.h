#ifndef WEBKIT_SORUCE_WTF_TYPE_TRAITS_H
#define WEBKIT_SORUCE_WTF_TYPE_TRAITS_H

namespace WTF {

/**
* If _judge is true, define WTF::EnableIf::type
*/
template<bool _judge, typename T>
struct EnableIf {
};

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
#define EnablePtrConvertibleArgDefn(From, To) \
    typpename WTF::EnableIf<WTF::IsPointerConvertible<From, To>::value, bool>::type

}

#endif // WEBKIT_SORUCE_WTF_TYPE_TRAITS_H
