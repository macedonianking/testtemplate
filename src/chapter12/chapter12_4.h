#ifndef CPRIMER_CHAPTER12_CHAPTER_12_4_H
#define CPRIMER_CHAPTER12_CHAPTER_12_4_H

#include <iostream>
#include <vector>

namespace chapter12_4 {

// Primary specialization.
template<typename T>
class List {
public:
    List() {
    }
};


// Full class specialization.
template<>
class List<void*> {
public:
    List() {
    }
    void Append(void *&ptr) {
        _M_data_list.push_back(ptr);
    }
    size_t length() const {
        return _M_data_list.size();
    }

private:
    std::vector<void*> _M_data_list;
};

// Partial specilization.
// The number of argument must match the number of the primary template.
// The parameter list of specialization can't have default arguments.
// Partial specialization is associated with primary template.
template<typename T>
class List<T*> {
public:
    List() {
    }

    size_t length() const {
        return _M_data_list.length();
    }

private:
    List<void*> _M_data_list;
};

void chapter12_4_tutorial();

}

#endif // CPRIMER_CHAPTER12_CHAPTER_12_4_H
