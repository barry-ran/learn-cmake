#include <iostream>

#include "myshared2.h"

static int staticGlobalTest = 2;

int myadd2(int add1, int add2) {
    std::cout << "+++++++++++++++++myshared2 myadd2+++++++++++++++++" << std::endl;
    std::cout << "staticGlobalTest from myshared2: value:" << staticGlobalTest << " address:" << (void*)&staticGlobalTest << std::endl;

    std::cout << "-----------------myshared2 myadd2-----------------" << std::endl;
    return add1 + add2;
}