#include <iostream>
#include <string>

// Debug Bool Flag
#define DEBUG 1

// Macro definition
#if DEBUG == 1
    #define LOG(x) std::cout << x << std::endl
#else
    #define LOG(x)
#endif


// Function definition using Macro
#define MAIN int main()\
{\
    LOG("Hello World");\
    std::cout << "This is an example of a macro" << std::endl;\
    return 0;\
}


MAIN
