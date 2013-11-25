#ifndef CFT_CONFIG_H
#define CFT_CONFIG_H 1

#if((   defined(_Windows) \
     || defined(_WINDOWS) \
     || defined(WIN32) \
     || defined(_WIN32) \
     || defined(__WIN32__) \
     || defined(_MSC_VER) \
     || defined(MINGW)\
    ) \
    && !defined(__CYGWIN__) \
   )

#  if defined(CFT_LIB_EXPORTS)
#    define CFT_LIB_DECLSPEC  __declspec(dllexport)
#  elif defined(LIB_IMPORTS)
#    define CFT_LIB_DECLSPEC  __declspec(dllimport)
#  else
#    define CFT_LIB_DECLSPEC
#  endif
#elif defined __CYGWIN__
#  define CFT_LIB_DECLSPEC
#else
#  define CFT_LIB_DECLSPEC
#endif

#endif //CFT_CONFIG_H
