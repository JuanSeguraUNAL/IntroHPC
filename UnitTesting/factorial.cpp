#include "factorial.h"

long factorial(long number)
{
    if(0 == number) return 1;
    if(number < 0){
        std::cerr << "Negative numbers not allowed. Returning -1\n";
        return -1;
    }
    return number <= 1 ? number : factorial(number-1)*number;
}

long PorDos(int n){
    return 2 * n;
}