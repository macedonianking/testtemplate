#ifndef WEBKIT_SOURCE_CONFIG_H
#define WEBKIT_SOURCE_CONFIG_H

// eg:ENABLE(ASSERT) -> defined(ENABLE_ASSERT) && ENABLE_ASSERT
// 定义了ENABLE_ASSERT宏并且设置的宏不是0
#define ENABLE(WTF_FEATURE) (defined ENABLE_##WTF_FEATURE && ENABLE_##WTF_FEATURE)

#endif // WEBKIT_SOURCE_CONFIG_H
