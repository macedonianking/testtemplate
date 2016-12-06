#ifndef WEBKIT_SOURCE_NULL_PTR_H
#define WEBKIT_SOURCE_NULL_PTR_H

/**
* Disallow definion form ClassName t = 0;
* Disallow assignment from t = 0;
*/
#define WTF_DISALLOW_CONSTRUCTOR_FROM_ZERO(ClassName) \
    ClassName(int)
#define WTF_DISALLOW_ASSIGN_FROM_ZERO(ClassName) \
    ClassName &operator=(int)

#endif