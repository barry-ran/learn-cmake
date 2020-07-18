#include <iostream>

#include "mystaticd.h"
#include "myshared2.h"

static int staticGlobalTest = 1;

int myadd_static(int add1, int add2) {
    std::cout << "+++++++++++++++++mystatic myadd_static+++++++++++++++++" << std::endl;
    std::cout << "staticGlobalTest from mystaticd: value:" << staticGlobalTest << " address:" << (void*)&staticGlobalTest << std::endl;

    myadd2(add1, add2);
    std::cout << "-----------------mystatic myadd_static-----------------" << std::endl;
    return add1 + add2;
}