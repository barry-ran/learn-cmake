#include <iostream>

#include "myshared.h"
#include "mystaticd.h"

static int staticGlobalTest = 2;

int myadd(int add1, int add2) {
    std::cout << "call myadd" << std::endl;
    std::cout << "staticGlobalTest from myshared: value:" << staticGlobalTest << " address:" << (void*)&staticGlobalTest << std::endl;

    myadd_static(add1, add2);
    return add1 + add2;
}