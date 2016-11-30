#include "chapter12/SkBitmap.h"

#include <stdint.h>
#include <memory.h>

#include "macros.h"

namespace chapter12 {

void SkBitmap::AllocPixelsInternal() {
    DCHECK(!mPixels);
    int allBytes = ComputeAllBytes();
    mPixels = (uint8_t*) malloc(sizeof(uint8_t) * allBytes);
    DCHECK(mPixels);
    memset(mPixels, 0, sizeof(uint8_t) * allBytes);
}

int SkBitmap::ComputeRowBytes() const {
    int bytesPerPixel = 0;
    int rowBytes;
    
    switch(mConfig) {
        case Sk_ARGB8888: {
            bytesPerPixel = 4;
            break;
        }
        case Sk_RGB565: {
            bytesPerPixel = 2;
            break;
        }
        default:{
            DCHECK(false);
            break;
        }
    }

    rowBytes = bytesPerPixel * mWidth + 3;
    rowBytes -= rowBytes % 4;
    return rowBytes;
}

}