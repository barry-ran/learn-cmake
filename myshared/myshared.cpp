#include <iostream>

#include "myshared.h"

int myadd(int add1, int add2) {
    std::cout << "call myadd" << std::endl;
    return add1 + add2;
}