#include <iostream>

#include "mystaticd.h"

static int staticGlobalTest = 1;

int myadd_static(int add1, int add2) {
    std::cout << "call myadd_static" << std::endl;
    std::cout << "staticGlobalTest from mystaticd: value:" << staticGlobalTest << " address:" << (void*)&staticGlobalTest << std::endl;
    return add1 + add2;
}