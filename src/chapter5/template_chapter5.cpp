#include "chapter5/template_chapter5.h"

namespace chapter5 {

void template_chapter5_1_tutorial() {
    std::bitset<10> set;
    print_bitset(set);
}

void template_chapter5_3_tutorial() {
    Stack<float> floatStack;
    Stack<int> intStack;
    
    intStack.Push(10);
    intStack.Push(20);
    intStack.Push(30);
    floatStack = intStack;
    
    while (!floatStack.IsEmpty()) {
        std::cout << floatStack.Top() << std::endl;
        floatStack.Pop();
    }
}

}

namespace chapter5_4 {

void template_chapter5_4_tutorial() {
    Stack<int, std::deque> intStack;
    intStack.Push(10);
    intStack.Push(20);
    intStack.Push(30);
    while (!intStack.IsEmpty()) {
        std::cout << intStack.Top() << std::endl;
        intStack.Pop();
    }
}

}