#ifndef CHAPTER12_SK_BITMAP_H
#define CHAPTER12_SK_BITMAP_H

#include <stdlib.h>

namespace chapter12 {

class SkBitmap {
public:
    enum Config {
        Sk_ARGB8888,
        Sk_RGB565,
    };

public:
    SkBitmap(Config config, int width, int height) 
    : mConfig(config), mWidth(width), mHeight(height), mPixels(NULL)
    {
    }

    ~SkBitmap() {
        if(mPixels) {
            free(mPixels);
            mPixels = NULL;
        }
    }

    int ComputeRowBytes() const;
    int ComputeAllBytes() const {
        return mHeight * ComputeRowBytes();
    }

private:
    void AllocPixelsInternal();

private:
    Config  mConfig;
    int     mWidth;
    int     mHeight;
    void    *mPixels;
};

}

#endif // CHAPTER12_SK_BITMAP_H
