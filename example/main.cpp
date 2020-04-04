#include <iostream>
#include <stdio.h>

#include "Config.h"
#ifdef USE_MYMATH
#include "mymath.h"
#else
#include <math.h>
#endif

int main()
{
    std::cout << "example: 4 sqrt is "
#ifdef USE_MYMATH
    << mysqrt(4) 
#else
    << sqrt(4) 
#endif
    << std::endl;

    getchar();
}
