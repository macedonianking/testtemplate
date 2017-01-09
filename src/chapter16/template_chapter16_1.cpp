#include "chapter16/template_chapter16_1.h"

#include <iostream>
#include <typeinfo>

namespace template_chapter16_1 {

class BaseTypeList {
public:
    typedef std::string t1;
    typedef std::string t2;
    typedef std::string t3;
    typedef std::string t4;
    typedef std::string t5;
    typedef std::string t6;
    typedef std::string t7;
    typedef std::string t8;
};

template<typename T1>
class SetType1 : public virtual BaseTypeList {
public:
    typedef T1 t1;
};

template<typename T2>
class SetType2 : public virtual BaseTypeList {
public:
    typedef T2 t2;
};

template<typename T3>
class SetType3 : public virtual BaseTypeList {
public:
    typedef T3 t3;
};

template<typename T, 
         int N>
class Discriminator : public T {
};

template<typename T1, typename T2, typename T3>
class TypeSelector : public Discriminator<T1, 1>, 
                     public Discriminator<T2, 2>, 
                     public Discriminator<T3, 3> {
};

template<typename T1 = std::string,
         typename T2 = std::string,
         typename T3 = std::string>
class BreadSlicer {
public:
    typedef TypeSelector<T1, T2, T3> type_selector;
    typedef typename type_selector::t1 t1;
    typedef typename type_selector::t2 t2;
    typedef typename type_selector::t3 t3;
};

void chapter16_1_tutorial() {
    typedef BreadSlicer<SetType3<int>> type;
    std::cout << typeid(type::t1).name() << std::endl;
    std::cout << typeid(type::t2).name() << std::endl;
    std::cout << typeid(type::t3).name() << std::endl;
}

}