#include "chapter14/chapter14.h"

#include <iostream>

namespace chapter14 {

RectangleGeo::RectangleGeo(int l, int t, int r, int b)
: mLeft(l), mTop(t), mRight(r), mBottom(b) 
{
}

RectangleGeo::~RectangleGeo()
{
}

void RectangleGeo::Draw() {
    std::cout << "RectangleGeo::Draw called" << std::endl;
}

void RectangleGeo::GetCenter(int *px, int *py) const {
}

}