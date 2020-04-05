#include <iostream>
#include <stdio.h>

#include "Config.h"
#ifdef USE_MYMATH
#include "mymath.h"
#else
#include <math.h>
#endif
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    const double inputValue = std::stod(argv[1]);

#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);
#endif
    std::cout << inputValue << " is " << outputValue << std::endl;

    getchar();
}
