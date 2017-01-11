#ifndef WTF_Config_h
#define WTF_Config_h

#define ENABLE(WTF_FEATURE) (defined ENABLE_##WTF_FEATURE && ENABLE_##WTF_FEATURE)
#define OS(WTF_FEATURE)     (defined(OS_##WTF_FEATURE) && OS_##WTF_FEATURE)

#endif // WTF_Config_h
