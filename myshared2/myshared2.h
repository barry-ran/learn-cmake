#pragma once

#if defined(_WIN32)
#  if defined(EXPORTING_MYSHARED)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // non windows
#  define DECLSPEC
#endif

int DECLSPEC myadd2(int add1, int add2);