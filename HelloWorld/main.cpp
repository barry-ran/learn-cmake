#include <iostream>
#include <stdio.h>

#ifdef USE_MYMATH
#include "mymath.h"
#else
#include <math.h>
#endif
#include "Config.h"

int main()
{
    std::cout << "Hello world 4 sqrt is "
#ifdef USE_MYMATH
    << mysqrt(4) 
#else
    << sqrt(4) 
#endif
    << std::endl;

    getchar();
}
