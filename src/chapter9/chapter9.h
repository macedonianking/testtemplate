#ifndef CPRIMER_CHAPTER9_CHAPTER9_H
#define CPRIMER_CHAPTER9_CHAPTER9_H

/**
* The context associated with the C++ template.
* <ol>
* <li>The context in which the template is defined.</li>
* <li>The context in which the templae is instantiated.</li>
* <li>The context associated with the template argument types.</li>
* </ol>
* Qualified name.
* Dependent name.
* Argument dependent lookup.
*/
namespace chapter9 {

template<template<typename> class T> 
class X
{
};

template<typename T>
class C {
public:
    C<T> *m_ptr;
    X<C> m_x;
};

}

#endif
