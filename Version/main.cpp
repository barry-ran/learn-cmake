#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include "Config.h"

int main (int argc, char *argv[])
{
    std::cout << argv[0] << " Version " 
              << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH;

    getchar();
    return 0;
}