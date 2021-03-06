#include <iostream>
#include <cmath>

double mysqrt(double input) {
    std::cout << "call mysqrt" << std::endl;
#if defined(HAVE_LOG) && defined(HAVE_EXP)
    double result = exp(log(input) * 0.5);
    std::cout << "Computing sqrt of " << input << " to be " << result
            << " using log and exp" << std::endl;
    return result;
#else
    return sqrt(input);
#endif
}