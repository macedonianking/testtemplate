#ifndef CPIMER_CHAPTER8_CHAPTER8_H
#define CPIMER_CHAPTER8_CHAPTER8_H

#include <vector>

namespace chapter8 {

template<typename T>
class List;

/*
* Primary template.
*/
template<typename T>
class List {
public:
    List() {
    }

    void Add(const T &t) {
        mDataList.push_back(t);
    }

    void Remove(int i) {
        mDataList.erase(mDataList.begin() + i);
    }

    int Size() {
        return mDataList.size();
    }

private:
    std::vector<T> mDataList;
};

template<typename T, typename U>
inline T implicit_cast(const U &u) {
    return u;
}

/**
* 模板在实例化的过程中先扫描所有的成员判断形势是否匹配,<br/>
* 对于非模板成员函数，在没有调用的情况下不实例化他的流程,<br/>
*/
template<typename T>
class TestIterator {
private:
    template<typename U>
    static char test(const typename U::iterator *);
    template<typename U>
    static int  test(...);

public:
    static constexpr bool value = sizeof(test<T>(0)) == sizeof(char);
};

void chapter8_2_tutorial();
}

#endif // CPIMER_CHAPTER8_CHAPTER8_H
