#ifndef CPRIMER_CHAPTER14_CHAPTER14_H
#define CPRIMER_CHAPTER14_CHAPTER14_H

// static polymorphism
// dynamic polymorphism
// generic programming

namespace chapter14 {

class GeoObj {
public:
    GeoObj() {}
    virtual ~GeoObj() {}

    virtual void Draw() = 0;
    virtual void GetCenter(int *xptr, int *yptr) const = 0;
};

class RectangleGeo: public GeoObj {
public:
    RectangleGeo(int l, int t, int r, int b);
    ~RectangleGeo();

    virtual void Draw();
    virtual void GetCenter(int *px, int *py) const;
private:
    int mLeft, mTop, mRight, mBottom;
};

void drawGeoObj(GeoObj *obj);

}

#endif // CPRIMER_CHAPTER14_CHAPTER14_H
