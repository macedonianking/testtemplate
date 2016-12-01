#ifndef CPIMER_CHAPTER8_CHAPTER8_H
#define CPIMER_CHAPTER8_CHAPTER8_H

#include <vector>

namespace chapter8 {

template<typename T>
class List;

/*
Primary template.
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

}

#endif // CPIMER_CHAPTER8_CHAPTER8_H
